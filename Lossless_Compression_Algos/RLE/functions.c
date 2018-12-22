/**********************************************************************
*
*  FILE NAME	: functions.c
*
*  DESCRIPTION  : Modular functions used to implement 
*				  RLE compression and decompression.
* 
*
*  DATE                 NAME                     REASON
*  31st Jan,2018        Shashi Shivaraju         ECE_6680_Lab_02
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/
#include "header.h" 

/*Static functions*/
static void rle_encode_with_marker(unsigned char *original_data,unsigned char *encoded_data,int file_size,unsigned int *encoded_data_size);
static void rle_encode_without_marker(unsigned char *original_data,unsigned char *encoded_data,int file_size,unsigned int *encoded_data_size);

static void rle_decode_with_marker(unsigned char *original_data,int file_size);
static void rle_decode_without_marker(unsigned char *original_data,int file_size);

/*Function to implement RLE encoding*/
void rle_encode(FILE *fpt,unsigned int file_size,int enable_marker)
{
	FILE *encode_fpt = NULL;
	unsigned char *original_data = NULL;
	unsigned char *encoded_data = NULL;
	int ret = 0;
	unsigned int encoded_data_size=0;
	char encoded_file[MAX_FILENAME] = {0};	/*character array to store the filename*/

	/*Memory Allocations*/
	original_data = (unsigned char*)calloc(file_size,sizeof(unsigned char));
	if(!original_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	/*Memory Allocations*/
	encoded_data = (unsigned char*)calloc(file_size*2,sizeof(unsigned char)); /*Allocation size twice to handle negative compression if any*/
	if(!encoded_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}


	ret = fread(original_data,1,file_size,fpt);/*read the data form file and store in a buffer*/
	if(ret != file_size)              /*check for invalid fread*/
	{
		printf("fread failed to read %d data from file",file_size); /*fread operation failed*/
		return;              /*return*/
	}

	if(enable_marker)
	{
		/*encode with marker*/
		rle_encode_with_marker(original_data,encoded_data,file_size,&encoded_data_size);
		strcpy(encoded_file,"RLE_ENCODED_WM.dump");
	}
	else
	{
		/*encode without marker*/
		rle_encode_without_marker(original_data,encoded_data,file_size,&encoded_data_size);
		strcpy(encoded_file,"RLE_ENCODED_WOM.dump");
	}

	/*write the encoded data to a file*/
	encode_fpt = fopen(encoded_file,"wb");
	if(!encode_fpt)
	{
		printf("fopen failed for %s",encoded_file);
		return;
	}

	ret = fwrite(encoded_data,1,encoded_data_size,encode_fpt);
	if(ret != encoded_data_size)
	{
		printf("frwite failed with %d\n",ret);
	}

	printf("\nRLE encoded file stored as %s with file size %d bytes\n",encoded_file,encoded_data_size);

	if(encode_fpt)
	{
		fclose(encode_fpt);
		encode_fpt = NULL;
	}

	if(original_data)
	{
		free(original_data);
		original_data = NULL;
	}

	if(encoded_data)
	{
		free(encoded_data);
		encoded_data = NULL;
	}

	return;
}

static void rle_encode_with_marker(unsigned char *original_data,unsigned char *encoded_data,int file_size,unsigned int *encoded_data_size)
{
	int i = 0,j=0;/*variable for the loop*/
	unsigned char cur = 0,next = 0;
	unsigned char count=1; /*default*/
	unsigned char marker = 0x00; /*Redundant runcount value used as marker to indicate RLE off/on*/ 
	unsigned char markerstatus = 0; 

	for(i=0;i<file_size;i++)
	{
		cur = original_data[i];

		/*check for end of the data or if run count is 255*/
		if(i == (file_size-1)||MAX_8BIT == count)
		{
			if(markerstatus)
			{
				encoded_data[j]=cur;
				j = j+1;
			}
			else
			{
				encoded_data[j]=count;
				encoded_data[j+1]= cur;
				j = j+2;
				count = 1;
			}
			
			continue;
		}

		/*Check if the data is equal to the marker*/
		if(0x00 == cur)
		{
			/*If data is equal to marker it will always be encoded with RLE ON */
			if(markerstatus)
			{
				encoded_data[j]=marker; /*RLE ON marker*/
				j = j+1;
				markerstatus = 0;
			}
		}

		next = original_data[i+1];

		if(cur == next)
		{
			if(markerstatus)
			{
				encoded_data[j]=marker; /*RLE ON marker*/
				j = j+1;
				markerstatus = 0; /*RLE ON indicator*/
			}

			count ++;
			continue;
		}
		else
		{	
			if(count > MIN_RUN_COUNT || 0x00 == cur)
			{
					encoded_data[j]=count;
					encoded_data[j+1]= cur;
					j = j+2;
					count = 1;

					if(0x00 == cur)
					{
						if(!markerstatus)
						{
							encoded_data[j]=marker; /*RLE OFF marker*/
							j = j+1;
							markerstatus = 1;	/*RLE OFF indicator*/
						}
					}
			}
			else
			{
				if(markerstatus)
				{
					encoded_data[j]=cur;
					j = j+1;
				}
				else
				{
						encoded_data[j]= marker; /*RLE off marker*/
						encoded_data[j+1]= cur;
						j = j+2;
						markerstatus = 1;  /*indicates that the RLE is off*/
				}
			}
		}
	}

	*encoded_data_size = j;
}


static void rle_encode_without_marker(unsigned char *original_data,unsigned char *encoded_data,int file_size,unsigned int *encoded_data_size)
{
	int i = 0,j=0;/*variable for the loop*/
	unsigned char cur = 0,next = 0;
	unsigned char count=1; /*default*/

	for(i=0;i<file_size;i++)
	{
		cur = original_data[i];

		/*check for end of the data or if run count is 255*/
		if(i == (file_size-1)||MAX_8BIT == count)
		{
			encoded_data[j]=count;
			encoded_data[j+1]= cur;
			j = j+2;
			count = 1;
			continue;
		}

		next = original_data[i+1];

		if(cur == next)
		{
			count ++;
			continue;
		}
		else
		{
			encoded_data[j]=count;
			encoded_data[j+1]= cur;
			j = j+2;
			count = 1;
		}
	}

	*encoded_data_size = j;
}

/*Function to implement RLE decoding*/
void rle_decode(FILE *fpt,unsigned int file_size,int enable_marker)
{

	unsigned char *original_data = NULL;
	int ret = 0;
	unsigned int decoded_data_size=0;
	char decoded_file[MAX_FILENAME] = {0};	/*character array to store the filename*/

	/*Memory Allocations*/
	original_data = (unsigned char*)calloc(file_size,sizeof(unsigned char));
	if(!original_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	ret = fread(original_data,1,file_size,fpt);/*read the data form file and store in a buffer*/
	if(ret != file_size)              /*check for invalid fread*/
	{
		printf("fread failed to read %d data from file",file_size); /*fread operation failed*/
		return;              /*return*/
	}

	if(enable_marker)
	{
		/*decode with marker*/
		rle_decode_with_marker(original_data,file_size);
	}
	else
	{
		/*decode without marker*/
		rle_decode_without_marker(original_data,file_size);
	}
	
	if(original_data)
	{
		free(original_data);
		original_data = NULL;
	}

	return;
}

static void rle_decode_with_marker(unsigned char *original_data,int file_size)
{
	FILE *decode_fpt = NULL;
	unsigned char *decoded_data = NULL;
	encoded_data *list_head = NULL,*new_data = NULL,*prev_data = NULL,*curr_data = NULL;
	encoded_data *head = NULL,*cur = NULL,*temp = NULL;
	char decoded_file[MAX_FILENAME] = {0};	/*character array to store the filename*/
	unsigned char marker = 0x00; /*Redundant runcount value used as marker to indicate RLE off/on*/
	unsigned char rle_status = 1;	/*1 = rle on;0 = rle off*/
	int decoded_data_size = 0;
	int i = 0,j=0,k=0;
	int ret = 0;

	/*Parse the encoded data for markers and 
	store the encoded data in runcount & byte form in an link list*/
	while (i < file_size)
	{
		if(marker == original_data[i] && 
			1 == rle_status) 
		{
			rle_status  = 0;	/*rle off*/
			i++;
			continue;
		}
		else if(marker == original_data[i] && 
			0 == rle_status)
		{
			rle_status  = 1;	/*rle on*/
			i++;
			continue;
		}

		new_data = (encoded_data*)malloc(sizeof(encoded_data));
		if(!new_data)
		{
			printf("memory allocation failed");
			return;
		}
		memset(new_data,0,sizeof(encoded_data));

		if(rle_status) /*rle on*/
		{
			new_data->runcount = original_data[i];
			new_data->byte_value = original_data[i+1];

			decoded_data_size = decoded_data_size + new_data->runcount;
			i = i+2; /*increment by 2 bytes*/
		}
		else	/*rle off*/
		{
			new_data->runcount = 1;
			new_data->byte_value = original_data[i];

			decoded_data_size = decoded_data_size + new_data->runcount;
			i++; /*increment by 1 byte*/
		}

		if(!list_head)
		{
			list_head = new_data;
			list_head->prev = NULL;
		}

		if(prev_data)
		{
			prev_data->next = new_data;
			new_data->prev = prev_data;
		}

		new_data->next = NULL;
		prev_data = new_data;

	}

	/*Memory Allocations*/
	decoded_data = (unsigned char*)calloc(decoded_data_size,sizeof(unsigned char));
	if(!decoded_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	head = list_head;
	cur = head;
	j = 0;
	while(head)
	{
		cur = head;
		for(i=0;i<cur->runcount;i++)
		{
			decoded_data[j] = cur->byte_value;
			j++;
		}
		head = cur->next; 
	}

	strcpy(decoded_file,"RLE_DECODED_WM.dump");

	/*write the encoded data to a file*/
	decode_fpt = fopen(decoded_file,"wb");
	if(!decode_fpt)
	{
		printf("fopen failed for %s",decoded_file);
		return;
	}

	ret = fwrite(decoded_data,1,decoded_data_size,decode_fpt);
	if(ret != decoded_data_size)
	{
		printf("frwite failed with %d\n",ret);
	}

	printf("\nRLE Decoded data saved as %s with file size %d bytes\n",decoded_file,decoded_data_size);

	/*Free the memory allocated*/
	destroy_list(list_head);

	if(decode_fpt)
	{
		fclose(decode_fpt);
		decode_fpt = NULL;
	}

	if(decoded_data)
	{
		free(decoded_data);
		decoded_data = NULL;
	}
}

static void rle_decode_without_marker(unsigned char *original_data,int file_size)
{
	FILE *decode_fpt = NULL;
	unsigned char *decoded_data = NULL;
	char decoded_file[MAX_FILENAME] = {0};	/*character array to store the filename*/
	int decoded_data_size = 0;
	int i = 0,j=0,k=0;
	int ret = 0;

	/*find the total size for the decoded data*/
	for(i=0;i<file_size;i=i+2)
	{
		decoded_data_size = decoded_data_size + original_data[i];
	}

	/*Memory Allocations*/
	decoded_data = (unsigned char*)calloc(decoded_data_size,sizeof(unsigned char));
	if(!decoded_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	for(i=0;i<file_size;i=i+2)
	{
		for(j=0;j<original_data[i];j++)
		{
			decoded_data[k] = original_data[i+1];
			k++;
		}
	}

	strcpy(decoded_file,"RLE_DECODED_WOM.dump");

	/*write the encoded data to a file*/
	decode_fpt = fopen(decoded_file,"wb");
	if(!decode_fpt)
	{
		printf("fopen failed for %s",decoded_file);
		return;
	}

	ret = fwrite(decoded_data,1,decoded_data_size,decode_fpt);
	if(ret != decoded_data_size)
	{
		printf("frwite failed with %d\n",ret);
	}

	printf("\nRLE Decoded data saved as %s with file size %d bytes\n",decoded_file,decoded_data_size);

	if(decode_fpt)
	{
		fclose(decode_fpt);
		decode_fpt = NULL;
	}

	if(decoded_data)
	{
		free(decoded_data);
		decoded_data = NULL;
	}

	return;
}


void destroy_list(encoded_data* list_head)
{
	encoded_data *curr = NULL;
	/*Deallocate the memory*/
	curr = list_head;
	while(list_head)
	{	
		curr = list_head;
		list_head = curr->next;
		free (curr);
		curr = NULL;
	}

}

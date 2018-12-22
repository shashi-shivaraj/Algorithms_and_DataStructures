/**********************************************************************
*
*  FILE NAME	: functions.c
*
*  DESCRIPTION  : Modular functions used to implement 
*				  LZW compression and decompression.
* 
*  PLATFORM		: Win32
*
*  DATE                 NAME                     REASON
*  07th Feb,2018        Shashi Shivaraju         ECE_6680_Lab_03
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/
#include "header.h" 

/*Function to create a table entry*/
table_data*  create_node(table_data **list_head,table_data *prev,
						 unsigned char* pattern,unsigned int len,
						 unsigned short int code)
{

	table_data *head = NULL ,*curr = NULL;

	/*allocate memory to add a table entry*/
	curr = (table_data*)malloc(sizeof(table_data));
	if(!curr)
	{
		printf("malloc failed\n");
		return NULL;
	}

	/*allocate memory to store the pattern*/
	curr->pattern = (unsigned char*)calloc(1,len * sizeof(unsigned char));
	if(!curr->pattern)
	{
		printf("calloc failed\n");
		return NULL;
	}

	/*update the table with the new entry*/
	if(!*list_head)
		*list_head = curr;

	if(prev)
		prev->next = curr;

	curr->next = NULL;

	curr->length = len;
	curr->code = code;

	copydata(curr->pattern,pattern,len);
	return curr;
}

/*Function to implement LZW encoding*/
void lzw_encode(FILE *fpt,unsigned int file_size)
{
	FILE *encode_fpt = NULL;
	unsigned char *original_data = NULL;
	unsigned short int *encoded_data = NULL;
	unsigned char *prev_bytes = NULL;
	table_data *head = NULL ,*curr = NULL;
	table_data *P_C_entry = NULL,*P_entry = NULL;
	unsigned char cur_byte = 0;

	int ret = 0,i = 0,j = 0,pattern_len = 0;
	unsigned int encoded_data_size=0;
	unsigned short int root = 0;
	char encoded_file[MAX_FILENAME] = {0};	/*character array to store the filename*/

	/*Memory Allocations*/
	original_data = (unsigned char*)calloc(file_size,sizeof(unsigned char));
	if(!original_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	/*Memory Allocations*/
	encoded_data = (unsigned short int*)calloc(file_size,sizeof(unsigned short int)); /*Allocation size twice to handle negative compression if any*/
	if(!encoded_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	prev_bytes = (unsigned char*)calloc(file_size,sizeof(unsigned char)); /*Allocation to handle largest possible pattern*/
	if(!prev_bytes)/*Error handling*/
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

	strcpy(encoded_file,"LZW_ENCODED.dump");
	/*write the encoded data to a file*/
	encode_fpt = fopen(encoded_file,"wb");
	if(!encode_fpt)
	{
		printf("fopen failed for %s",encoded_file);
		return;
	}

	/*initialize the table data with all root symbols*/
	for(root=0;root<256;root++)
	{
		curr = create_node(&head,curr,&root,1,root);
	}

	root = 255;

	/*encode the data using LZW compression algo*/

	/*first byte will always be in the table*/
		cur_byte = original_data[0];
		/*prev+cur_byte*/
		copydata(prev_bytes+pattern_len,&cur_byte,1);
		pattern_len ++;

	for(i = 1;i<file_size;i++)
	{
		/*Find the table entry for P(prev bytes pattern)*/
		P_entry = check_pattern(head,prev_bytes,pattern_len);
		if(!P_entry) /*previous pattern will always be in the table*/
		{
			printf("This is a bug in code\n");
		}

		cur_byte = original_data[i];
		/*prev bytes +cur_byte*/
		copydata(prev_bytes+pattern_len,&cur_byte,1);
		pattern_len ++;
		
		/*Find the table entry for  P+C (prev bytes +curr byte pattern)*/
		P_C_entry = check_pattern(head,prev_bytes,pattern_len);
		if(P_C_entry)
		{
			/*pattern already has an entry in table*/
			if(i == (file_size-1)) /*last byte of the file*/
			{
				/*output code for P = P+C */
				memcpy(encoded_data+encoded_data_size,&P_C_entry->code,2);
				encoded_data_size = encoded_data_size+1;
			}
		}
		else
		{
		   /*pattern to be added to the table*/
			root++;
			curr = create_node(&head,curr,prev_bytes,pattern_len,root);

			/*output code for P*/
			memcpy(encoded_data+encoded_data_size,&P_entry->code,2);
			encoded_data_size = encoded_data_size+1;
			
			memset(prev_bytes,0,file_size);
			copydata(prev_bytes,&cur_byte,1);
			pattern_len = 1;

			if(i == (file_size-1)) /*last byte of the file*/
			{
				/*output code for P = C*/
				P_entry = check_pattern(head,prev_bytes,pattern_len);
				if(!P_entry) /*previous pattern will always be in the table*/
				{
					printf("This is a bug in code\n");
				}
				memcpy(encoded_data+encoded_data_size,&P_entry->code,2);
				encoded_data_size = encoded_data_size+1;
			}
		}
	}

	printf("\nLZW encoded file stored as %s with file size %d bytes\n",encoded_file,encoded_data_size*2);

	ret = fwrite(encoded_data,2,encoded_data_size,encode_fpt);
	if(ret != encoded_data_size)
	{
		printf("fwrite failed with %d\n",ret);
	}

	if(encode_fpt)
	{
		fclose(encode_fpt);
		encode_fpt = NULL;
	}

	/*Memory deallocation*/

	destroy_list(head);

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

	if(prev_bytes)
	{
		free(prev_bytes);
		prev_bytes = NULL;
	}

	return;
}

/*Function to implement LZW decoding*/
void lzw_decode(FILE *fpt,unsigned int file_size)
{
	FILE *decode_fpt = NULL;
	unsigned short int *original_data = NULL;
	unsigned char *X_Z_pattern = NULL;
	table_data *head = NULL ,*curr = NULL;
	table_data *P_C_entry = NULL,*P_entry = NULL,*C_entry = NULL;

	unsigned short int cur_code = 0,prev_code = 0;
	unsigned short int root = 0;
	unsigned char cur_byte = 0;

	int ret = 0,i = 0;
	unsigned int decoded_data_size=0;
	char decoded_file[MAX_FILENAME] = {0};	/*character array to store the filename*/

	/*Memory Allocations*/
	original_data = (unsigned short int*)calloc(file_size,sizeof(unsigned short int));
	if(!original_data)/*Error handling*/
	{
		printf("memory allocation failed\n");/*calloc operation failed*/
		return;		/*return*/
	}

	ret = fread(original_data,2,file_size/2,fpt);/*read the data form file and store in a buffer*/
	if(ret != file_size/2)              /*check for invalid fread*/
	{
		printf("fread failed to read %d data from file",file_size); /*fread operation failed*/
		return;              /*return*/
	}

	strcpy(decoded_file,"LZW_DECODED.dump");
	/*write the encoded data to a file*/
	decode_fpt = fopen(decoded_file,"wb");
	if(!decode_fpt)
	{
		printf("fopen failed for %s",decoded_file);
		return;
	}

	/*initialize the table data with all root symbols*/
	for(root=0;root<256;root++)
	{
		curr = create_node(&head,curr,&cur_byte,1,root);
		cur_byte ++;
	}

	root = 255;
	cur_code = 0; 

	/*decode the data using LZW decompression algo*/

	/*first byte will always be in the table*/
	cur_code = original_data[0];

	/*Find the table entry for C(Current code)*/
	C_entry = check_code(head,cur_code);
	if(!C_entry) /*previous pattern will always be in the table*/
	{
		printf("This is a bug in code\n");
	}
	
	/*Output pattern for C*/
	ret = fwrite(C_entry->pattern,1,C_entry->length,decode_fpt);
	if(ret != C_entry->length)
	{
		printf("frwite failed with %d\n",ret);
	}
	decoded_data_size = decoded_data_size+ret;

	for(i=1;i<file_size/2;i++)
	{
		prev_code = cur_code;
		cur_code = original_data[i];

		/*Find the table entry for P(prev code)*/
		P_entry = check_code(head,prev_code);
		if(!P_entry) /*previous pattern will always be in the table*/
		{
			printf("This is a bug in code\n");
		}

		X_Z_pattern = (unsigned char*)calloc(P_entry->length+1,sizeof(unsigned char));
		if(!X_Z_pattern)/*Error handling*/
		{
			printf("memory allocation failed\n");/*calloc operation failed*/
			return;		/*return*/
		}
		copydata(X_Z_pattern,P_entry->pattern,P_entry->length);

		C_entry = check_code(head,cur_code);
		if(C_entry) 
		{
			/*X = pattern for P;
			Z = 1st char of pattern for C;
			Add X+Z to table;*/
			copydata(X_Z_pattern+P_entry->length,C_entry->pattern,1);
			root++;
			curr = create_node(&head,curr,X_Z_pattern,P_entry->length+1,root);

			/*Output C pattern*/
			ret = fwrite(C_entry->pattern,1,C_entry->length,decode_fpt);
			if(ret != C_entry->length)
			{
				printf("fwrite failed with %d\n",ret);
			}
			decoded_data_size = decoded_data_size+ret;
		}
		else
		{

			/*X = pattern for P;
			  Z = 1st char of pattern for P;
			  Add X+Z to table;*/
			copydata(X_Z_pattern+P_entry->length,P_entry->pattern,1);
			root++;
			curr = create_node(&head,curr,X_Z_pattern,P_entry->length+1,root);
			
			/*Output X+Z pattern*/
			ret = fwrite(X_Z_pattern,1,P_entry->length+1,decode_fpt);
			if(ret != P_entry->length+1)
			{
				printf("frwite failed with %d\n",ret);
			}
			decoded_data_size = decoded_data_size+ret;
		}

		/*free the memory*/
		if(X_Z_pattern)
		{
			free(X_Z_pattern);
			X_Z_pattern = NULL;
		}
	}

	printf("\nLZW Decoded data saved as %s with file size %d bytes\n",decoded_file,decoded_data_size);

	/*Free the memory allocated*/

	if(decode_fpt)
	{
		fclose(decode_fpt);
		decode_fpt = NULL;
	}

	destroy_list(head);
	
	if(original_data)
	{
		free(original_data);
		original_data = NULL;
	}

	return;
}

/*Function to find the pattern in the table*/
table_data* check_pattern(table_data *head,unsigned char* pattern,int pattern_len)
{
	table_data *curr = NULL;
	curr = head;

	while(curr)
	{	
		if(pattern_len == curr->length)
		{
			if(0 == cmpdata(curr->pattern,pattern,pattern_len))
			{
				return curr; /*pattern found in the table*/
			}
		}
		curr = curr->next;
	}

	return NULL; /*pattern not found in the table*/
}

/*Function to find the code in the table*/
table_data* check_code(table_data *head,unsigned short int code)
{
	table_data *curr = NULL;
	curr = head;

	while(curr)
	{	
		if(code == curr->code)
		{
			return curr; /*code found in the table*/
		}
		curr = curr->next;
	}

	return NULL; /*code not found in the table*/
}

/*Function to check if bytes are similar*/
int cmpdata(unsigned char *data_one,unsigned char *data_two,int len)
{
	int i = 0,ret = 0;

	for(i = 0;i<len;i++)
	{
		if(data_one[i] != data_two[i])
		{
			return -1; /*not similar*/
		}
	}
	return 0; /*similar  data*/
}

/*Function to copy data in bytes*/
void copydata(unsigned char *dest,unsigned char *src,unsigned int len)
{
	int i = 0;
	for(i=0;i<len;i++)
	{
		dest[i] = src[i];
	}
}

/*function to delete the table*/
void destroy_list(table_data* list_head)
{
	table_data *curr = NULL;
	/*Deallocate the memory*/
	curr = list_head;
	while(list_head)
	{	
		curr = list_head;
		list_head = curr->next;

		if(curr->pattern)
			free(curr->pattern);
		curr->pattern = NULL;

		free (curr);
		curr = NULL;
	}

}

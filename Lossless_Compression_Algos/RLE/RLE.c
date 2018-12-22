/**********************************************************************
*
*  FILE NAME	: RLE.c
*
*  DESCRIPTION  : Implement RLE compression and decompression.
* 
*  PLATFORM		: Linux
*
*  DATE                 NAME                     REASON
*  31st Jan,2018        Shashi Shivaraju         ECE_6680_Lab_02
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/
#include "header.h" 

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])/*main function of the program*/
{
	FILE* fp = NULL;	/*file pointer to access the file*/
	char filename[MAX_FILENAME] = {0};	/*character array to store the filename*/
	unsigned int file_size = 0;	/*variable to store file size in bytes*/
	char option = 0;
	char marker_option = 0;
	int enable_marker = FALSE;
	unsigned int time1 = 0,time2 =0,timediff = 0; 

	while(1)
	{

printf("*************************************\n\
**************RLE CODEC**************\n\
*************************************\n");
printf("Select the codec option\n\n\
Enter 1 for Compression\n\
Enter 2 for Decompression\n\
Enter 0 to Exit the program\n");

		scanf(" %c",&option);


		if('1' == option || '2' == option)
		{
			printf("\nEnter the filename\n");
			scanf("%s",filename);

			fp = fopen(filename,"rb");
			if(!fp)
			{
				printf("fopen failed for %s",filename);
				return -1;
			}

			fseek(fp, 0L, SEEK_END);
			file_size = ftell(fp);
			fseek(fp, 0L, SEEK_SET);
			printf("\nThe original file size is %d\n",file_size);
		}

		switch(option)
		{
		case '1':
			{
				printf("\nEnter 5 for compression with marker or any other key for default compression\n");

				scanf(" %c",&marker_option);
				if('5' == marker_option)
				{
					enable_marker = TRUE;
					printf("\nEncode with marker enabled\n");
				}
				else
				{
					enable_marker = FALSE;
					printf("\nEncode without marker enabled\n");
				}

				//time1 = timeGetTime();
				rle_encode(fp,file_size,enable_marker);
				//time2 = timeGetTime();

				//timediff = time2-time1;
				//printf("\nEncode total time = %d\n",timediff);
			}
			break;
		case '2':
			{
				printf("\nEnter 7 for decompression of data with markers or any other key for default decompression\n");

				scanf(" %c",&marker_option);
				if('7' == marker_option)
				{
					enable_marker = TRUE;
					printf("\nDecode with marker enabled\n");
				}
				else
				{
					enable_marker = FALSE;
					printf("\nDecode without marker enabled\n");
				}

				//time1 = timeGetTime();
				rle_decode(fp,file_size,enable_marker);
				//time2 = timeGetTime();
				
				//timediff = time2-time1;
				//printf("\nDecode total time = %d\n",timediff);

			}
			break;
		case '0':
			{
				printf("\nexiting the program\n");
			}
			break;
		default:
			{
				printf("\ninvalid option: %d;Retry\n",option);
				break;
			}
		}

		if(fp)
		{
			fclose(fp);
			fp = NULL;
		}

		if('0' == option)
		{
			break;
		}


	}

	return 0;
}

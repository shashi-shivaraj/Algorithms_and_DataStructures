/**********************************************************************
*
*  FILE NAME	: Huffman.c
*
*  DESCRIPTION  : Implement Huffman compression and decompression.
* 
*  PLATFORM		: Win32
*
*  DATE                 NAME                     REASON
*  17th Feb,2018        Shashi Shivaraju         ECE_6680_Lab_04
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/
#include "header.h" 

int main(int argc, char *argv[])/*main function of the program*/
{
	FILE* fp = NULL;	/*file pointer to access the file*/
	char filename[MAX_FILENAME] = {0};	/*character array to store the filename*/
	unsigned int file_size = 0;	/*variable to store file size in bytes*/
//	unsigned int time1 = 0,time2 =0,timediff = 0; 
	char option = 0;

	while(1)
	{

		printf("*************************************\n\
**************Huffman CODEC**************\n\
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
			//	time1 = timeGetTime();
				/*function to encode the data*/
				huffman_encode(fp,file_size);
				
			/*	time2 = timeGetTime();

				timediff = time2-time1;
				printf("\nEncode total time = %d\n",timediff);*/
			}
			break;
		case '2':
			{
			//	time1 = timeGetTime();
				/*function to decode the data*/
				huffman_decode(fp,file_size);
				
		/*		time2 = timeGetTime();
				
				timediff = time2-time1;
				printf("\nDecode total time = %d\n",timediff);*/
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
			break; /*exit the program*/
		}
	}

	return 0;
}

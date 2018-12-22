/**********************************************************************
*
*  FILE NAME	: header.h
*
*  DESCRIPTION  : Header file
*
*  DATE                 NAME                    REASON
*  31st Jan,2018        ShashiShivaraju         ECE_6680_Lab_02
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	/*included for strcmp() and memset() api*/


/*Macro definations*/
#define MAX_8BIT	255
#define MIN_8BIT	0		
#define MAX_FILENAME	500

#define MIN_RUN_COUNT	1 

/*decalrations of datatypes*/
typedef struct __encoded_data
{
	unsigned char runcount;
	unsigned char byte_value;
	struct encoded_data *next;
	struct encoded_data *prev;
}encoded_data;


/*Function Prototypes*/

/*Function to implement RLE encoding*/
void rle_encode(FILE *fpt,unsigned int file_size,int enable_marker);

/*Function to implement RLE decoding*/
void rle_decode(FILE *fpt,unsigned int file_size,int enable_marker);

/*Function to deleate the linked list*/
void destroy_list(encoded_data* list_head);

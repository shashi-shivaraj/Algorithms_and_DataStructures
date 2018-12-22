/**********************************************************************
*
*  FILE NAME	: header.h
*
*  DESCRIPTION  : Header file
* 
*  PLATFORM		: Linux
*
*  DATE                 NAME                    REASON
*  07th Feb,2018        ShashiShivaraju         ECE_6680_Lab_03
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Macro definations*/
#define MAX_8BIT	255
#define MIN_8BIT	0		
#define MAX_FILENAME	500

/*decalrations of datatypes*/
typedef struct __table_data
{
	unsigned int  length;
	unsigned char *pattern;
	unsigned short int	code;
	struct table_data *next;
}table_data;


/*Function Prototypes*/

/*Function to create a table entry*/
table_data* create_node(table_data **list_head,table_data* prev,
						unsigned char* pattern,unsigned int len,
						unsigned short int code);

/*Function to implement LZW encoding*/
void lzw_encode(FILE *fpt,unsigned int file_size);

/*Function to implement LZW decoding*/
void lzw_decode(FILE *fpt,unsigned int file_size);

/*Function to copy data in bytes*/
void copydata(unsigned char *dest,unsigned char *src,unsigned int len);

/*Function to find the pattern in the table*/
table_data* check_pattern(table_data *head,unsigned char* pattern,int pattern_len);

/*Function to find the code in the table*/
table_data* check_code(table_data *head,unsigned short int code);

/*Function to check if bytes are similar*/
int cmpdata(unsigned char *data_one,unsigned char *data_two,int len);

/*Function to deleate the linked list*/
void destroy_list(table_data* list_head);

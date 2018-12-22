/**********************************************************************
*
*  FILE NAME	: header.h
*
*  DESCRIPTION  : Header file
* 
*  PLATFORM		: Win32
*
*  DATE                 NAME                    REASON
*  17th Feb,2018        ShashiShivaraju         ECE_6680_Lab_03
*                       [C88650674]
***********************************************************************/

/*Header file inclusions*/ 
#include <stdio.h>
#include <stdlib.h>

/*Macro definations*/
#define MAX_8BIT	256
#define MIN_8BIT	0		
#define MAX_FILENAME	500

#define BYTE2BITS	8

#undef DEBUG /*enable for printing symbol and their corresponding bit pattern on console*/

/*declarations of datatype*/

/*node in a binary tree*/
typedef struct __node_data
{
	unsigned int  freq;
	unsigned char byte;
	unsigned char *pattern;
	unsigned int  pattern_len;
	unsigned char isSymbol;
	struct node_data *root;
	struct node_data *left;
	struct node_data *right;
	struct node_data *next;

}node_data;


/*Function Prototypes*/

/*Function to implement Huffman encoding*/
void huffman_encode(FILE *fpt,unsigned int file_size);

/*Function to implement Huffman decoding*/
void huffman_decode(FILE *fpt,unsigned int file_size);

/*Function to create a node*/
node_data*  create_node(node_data **list_head,node_data *prev,
						unsigned char byte,unsigned int freq,
						node_data *left,node_data *right,
						unsigned char isSymbol);

/*Function to sort the linked list*/
void sort_list(node_data **head,node_data **tail);

/*Function to build a Binary Tree based on the sorted link list*/
void CreateBinaryTree(node_data **head,node_data **tail);

/*Function to traverse the binary tree and update the bit codes*/
void TraverseBinaryTree(node_data *symbol_list_head,unsigned int rootfreq);

/*Function to copy data in bytes 
Have modified the function to reverse the order*/
void copydata(unsigned char *dest,unsigned char *src,unsigned int len);

/*Function to Create the header info of the encoded file*/
void CreateHeaderInfo(unsigned char *dest,node_data *head,unsigned char *symbol_count,unsigned int *len);

/*Function to Encode the symbols in the file with its corresponding bit sequences*/
void EncodeData(unsigned char * encoded_data,
				unsigned char * original_data,unsigned int file_size,
				node_data *head, node_data **node_pointers,
				unsigned int *encoded_data_size,unsigned int *total_bit_count);

/*Function to deallocate the memory of the tree*/
void Destroy_Tree(node_data *root_node);

/*Function to parse the header of the encoded file*/
void Parse_Header(unsigned char *original_data,node_data **head,
				  node_data **tail,unsigned int *bits2decode,
				  unsigned int *byteindex,unsigned int *uncompress_size);

/*Decode the encoded data by finding the pattern symbol in the binary tree*/
void DecodeData(node_data *head,
				unsigned char * original_data,unsigned char *decoded_data,
				unsigned int bits2decode,unsigned int byteindex,
				unsigned int file_size,unsigned int *decoded_size);

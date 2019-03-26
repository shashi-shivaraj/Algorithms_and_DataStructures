//program that takes as input a sequence of packet ids and re-orders them

//header file inlcusion
#include <iostream>
#include <fstream>
#include "intset.h"

//main function of the program
int main(int argc,char* argv[])
{
	int ret = 0;
	
	//check for valid args
	if(argc != 2)
	{
		std::cout << "[USAGE] ./exe input.txt" <<std::endl;
		return -1;
	}
	
	//open file to read the sequence
	std::fstream s(std::string(argv[1]),std::ios_base::in); 
	if (!s.is_open()) 
	{
		std::cout << "failed to open file "<<std::endl;
		return -1;
	}
	
	//read sequence length from file
	int seq_len = 0;
	s>>seq_len;
	std::cout<<"sequence len = "<<seq_len<<std::endl;
	
	//
	IntSet packet_seq; 
	
	//allocate memory for the sequence
	int* seq = new int[seq_len];
	//build the bst
	for(int i = 0;i<seq_len;i++)
	{
		s >> seq[i];
		packet_seq.insert(seq[i]);
	}
	
	//print the bst inorder
	packet_seq.print();
	
CLEANUP:	
	delete []seq;
	
	return ret;
}

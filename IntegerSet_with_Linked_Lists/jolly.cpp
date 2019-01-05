//program to determine is a sequence of number is a jolly or not
//using integer set data structure with sorted link list

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
	IntSet diff_seq; 
	
	//allocate memory for the sequence
	int* seq = new int[seq_len];
	s >> seq[0]; //read first element of sequence
	for(int i = 1;i<seq_len;i++)
	{
		s >> seq[i];
		//calculate the absolute diff b/w 
		// two consecutive terms and add it into integer set.
		diff_seq.insert(std::abs(seq[i]-seq[i-1]));
	}
	
	//print the list
	//diff_seq.print();
	
	bool retb = false;
	//check if the sequence if jolly
	for(int i=1;i<seq_len;i++)
	{	
		if(!diff_seq.find(i))
		{
			std::cout<<"Not a Jolly sequence: Not Found key: "<<i<<std::endl;
			goto CLEANUP;
		}
	}
	
	std::cout<<"It is a jolly sequence"<<std::endl;
	
CLEANUP:	
	delete seq;
	
	return ret;
}

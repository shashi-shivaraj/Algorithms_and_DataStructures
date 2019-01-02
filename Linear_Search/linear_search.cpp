/**********************************************************************
*
*  FILE NAME	: linear_search.cpp
*
*  DESCRIPTION  : Implementation of linear_search algorithm.
* 
*  PLATFORM		: Linux
***********************************************************************/

//header file inclusion
#include <iostream>

//main function of the program
int main()
{
	int *digits = NULL;
	int count = 0;
	int key = 0;
	int i = 0,flag = 0;
	
	//get the array limits
	std::cout<<"enter the total number of digits"<<std::endl;
	std::cin>>count;
	
	if(!count)
	{
		std::cout<<"total numbers must be above 0"<<std::endl;
	}
	
	//allocate heap memory
	digits = new int[count];
	
	//get the input numbers
	std::cout<<"enter the numbers"<<std::endl;
	for(i=0;i<count;i++)
	{
		std::cin>>digits[i];
	}
	
	//get the key number
	std::cout<<"enter the digit to be searched"<<std::endl;
	std::cin>>key;
	
	//perform linear search
	//Amortized Analysis = O(N)
	
	for(i=0;i<count;i++)
	{
		if(key == digits[i])
		{
			std::cout<<"key found at index = "<<i<<std::endl;
			flag = 1;
			break;
		}
	}
	
	if(!flag)
		std::cout<<"key not found"<<std::endl;
		
	return 0;
}

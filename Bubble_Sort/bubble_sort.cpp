/**********************************************************************
*
*  FILE NAME	: bubble_sort.cpp
*
*  DESCRIPTION  : Implementation of bubble sort algorithm.
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
	int i = 0;
	
	//get the array limits
	std::cout<<"enter the total number of digits"<<std::endl;
	std::cin>>count;
	
	if(count<1)
	{
		std::cout<<"total numbers must be above 0"<<std::endl;
	}
	
	//allocate heap memory
	digits = new int[count];
	
	std::cout<<"The input list is :"<<std::endl;
	//get the input numbers
	for(i=0;i<count;i++)
	{
		digits[i] = std::rand() % 100;
		std::cout<<digits[i]<<std::endl;
	}
		
	bool isSorted = false;
	int temp = 0,pass = 0;
	
	//perform bubble sort
	//Amortized Analysis = O(N*N)
	while(!isSorted)
	{
		isSorted = true;
		for(i=0;i<count-1-pass;i++)
		{	
			if(digits[i] > digits[i+1])
			{
				//swap
				temp = digits[i+1];
				digits[i+1] = digits[i];
				digits[i] = temp;
				
				isSorted = false;
			}
		}
		pass++;	
	}
	
	
	std::cout<<"The sorted list is :"<<std::endl;
	//get the input numbers
	for(i=0;i<count;i++)
	{
		std::cout<<digits[i]<<std::endl;
	}
		
CLEANUP:
		delete []digits;
		
	return 0;
}

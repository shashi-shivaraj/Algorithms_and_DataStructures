/**********************************************************************
*
*  FILE NAME	: insertion_sort.cpp
*
*  DESCRIPTION  : Implementation of insertion sort algorithm.
* 
*  PLATFORM		: Linux
***********************************************************************/

//header file inclusion
#include <iostream>
#include <cstdlib>
#include <ctime>


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
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	//get the input numbers
	for(i=0;i<count;i++)
	{
		digits[i] = std::rand() % 100;
		std::cout<<digits[i]<<std::endl;
	}
	
	//perform insertion sort
	//Amortized Analysis = O(N*N)
	//check each element with the previous values and swap
	
	for(i=1;i<count;i++)
	{
		int pos = i;
		for(int j = i-1;j >= 0;j--)
		{
			if(digits[pos] < digits[j])
			{
				std::swap(digits[pos],digits[j]);
				pos = j;
			}
		}
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

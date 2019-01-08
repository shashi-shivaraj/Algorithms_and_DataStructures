/**********************************************************************
*
*  FILE NAME	: select_sort.cpp
*
*  DESCRIPTION  : Implementation of select sort algorithm.
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
		
	int j = 0,min = 0,min_index = 0;
	
	//perform select sort
	//Amortized Analysis = O(N*N)
	for(i = 0;i < count - 1; i ++) //last element will be automatically sorted 
	{
		if(i+1 < count)//lets assume first value is min
		{
			min = digits[i+1];
			min_index = i+1;
		}
		
		//no need to check the sorted elements for min value
		for(j = i+1; j < count;j++) //swap with the least value in the list 
		{
			if(min > digits[j])
			{
				min = digits[j];
				min_index = j;
			}
		}
		
		if(min < digits[i])//swap digits if lesser value found
			std::swap(digits[i],digits[min_index]);
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

/**********************************************************************
*
*  FILE NAME	: Binary_search.cpp
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
	int begin = 0,end = 0,middle = 0;
	
	//get the array limits
	std::cout<<"enter the total number of digits"<<std::endl;
	std::cin>>count;
	
	if(count<2)
	{
		std::cout<<"total numbers must be above 1"<<std::endl;
	}
	
	//allocate heap memory
	digits = new int[count];
	
	//get the input numbers
	std::cout<<"enter the numbers in ascending order [sorted]"<<std::endl;
	for(i=0;i<count;i++)
	{
		std::cin>>digits[i];
	}
	
	//get the key number
	std::cout<<"enter the digit to be searched"<<std::endl;
	std::cin>>key;
	
	//check if the array is sorted
	for(i=0;i<count-1;i++)
	{
		if(digits[i] > digits[i+1])
		{
			std::cout<<"entered array is not sorted in ascending order"<<std::endl;
			goto CLEANUP;
		}
	}
	
	
	begin = 0;
	end = count;
	middle = count/2;
	
	//perform linear search
	//Amortized Analysis = O(log(N))
	while(begin < end)
	{
		if(key == digits[middle])
		{
			std::cout<<"key found at index = "<<middle<<std::endl;
			flag = 1;
			break;
		}
		else if(key > digits[middle])
		{
			begin = middle + 1;
			middle = (end + begin)/2;
		}
		else
		{
			end = middle;
			middle = (end + begin)/2; 
		}
	}
	
	if(!flag)
		std::cout<<"key not found"<<std::endl;
		
CLEANUP:
		delete digits;
		
	return 0;
}

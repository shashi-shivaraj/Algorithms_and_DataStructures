/******************************************************************************
*
*  FILE NAME	: inplace_shuffle.cpp
*
*  DESCRIPTION  : Implementation of Inplace shuffle using divide and conquere.
* 
*  PLATFORM		: Linux
*******************************************************************************/

//header file inclusion
#include <iostream>

//function prototype
void shuffle_wrapper(int *arr,int len);
void shuffle(int *arr,int start,int end);

//main function of the program
int main()
{
	int *digits = NULL;
	int count = 0;
	int i = 0;
	int n = 0;
	
	//get the array limits
	std::cout<<"enter the value of n [must be a power of 2]"<<std::endl;
	std::cin>>count;
	
	
	//check if the number is power of 2
	n = count;
	if(n & n-1)
	{
		std::cout<<"n is not a power of 2"<<std::endl;
		return -1;
	}
	
	//int bitcount = 0;
	//n = count;
	//while(n)
	//{
		//int bit = n & 0x01;
		//if(bit)
			//bitcount++;
		//n = n >> 1;
	//}
	
	//if(bitcount != 1 )
	//{
		//std::cout<<"n is not a power of 2"<<std::endl;
		//return -1;
	//}
	
	if(count<1)
	{
		std::cout<<"total numbers must be above 0"<<std::endl;
	}
	
	std::cout<<"The array is of size "<<2*count<<std::endl;
	
	//allocate heap memory
	digits = new int[count*2];
	
	std::cout<<"The input array is :"<<std::endl;
	//get the input numbers
	for(i=0;i<count*2;i++)
	{
		i<count?digits[i] = 0:digits[i] = 1;
		std::cout<<digits[i]<<std::endl;
	}
		
	//perform inplace shuffle
	shuffle_wrapper(digits,count*2);
	
	std::cout<<"The shuffled list is :"<<std::endl;
	//get the input numbers
	for(i=0;i<count*2;i++)
	{
		std::cout<<digits[i]<<std::endl;
	}
		
CLEANUP:
		delete []digits;
		
	return 0;
}


void shuffle_wrapper(int *arr,int len)
{
	shuffle(arr,0,len);
}

void shuffle(int *arr,int start,int len)
{
	if(len <= 2)
		return; //no shuffle possible
		
	//std::cout<<"start = "<<start<<"len = "<<len<<std::endl;
		
	int swap_index_one = (len)/4;
	int swap_index_two = (len)/2;
	
	//std::cout<<"swap_index_one = "<<swap_index_one<<"swap_index_two = "<<swap_index_two<<std::endl;
		
	int j = start+swap_index_two;
	for(int i = start+swap_index_one;i < start+swap_index_two;i++)
	{
		std::swap(arr[i],arr[j]);
		j++;
	} 
	
	shuffle(arr,start,swap_index_two);
	shuffle(arr,start+swap_index_two,len - swap_index_two);	
}


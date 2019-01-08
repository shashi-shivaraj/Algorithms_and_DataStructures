/**********************************************************************
*
*  FILE NAME	: quick_sort.cpp
*
*  DESCRIPTION  : Implementation of quick sort algorithm.
* 
*  PLATFORM		: Linux
***********************************************************************/

//header file inclusion
#include <iostream>
#include <utility>

//function declaration
void quick_sort(int * arr,int len);
void sort(int *arr,int leftstart,int rightend);
int partition(int * arr,int start,int end);


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
		digits[i] = count - i ;
		std::cout<<digits[i]<<std::endl;
	}
		
	//call quick sort wrapper
	quick_sort(digits,count);
	
	std::cout<<"The sorted list is :"<<std::endl;
	for(i=0;i<count;i++)
	{
		
		std::cout<<digits[i]<<std::endl;
		//check if the list is sorted
		if(i > 0 && digits[i] < digits[i-1])
		{
			std::cout<<"array not sorted : "<< digits[i] <<std::endl;
			break;
		}	
	}
		
	delete []digits;
		
	return 0;
}

//function definations
void quick_sort(int *arr,int len)
{
	//call sorting function with array start and end index
	sort(arr,0,len-1);
}

void sort(int *arr,int start,int end)
{
	int index = 0; //partition index
	
	if(start < end)
	{
		index = partition(arr,start,end); //partition the array wrt to pivot
		//recursively call sort on the two partitions
		sort(arr,start,index-1);
		sort(arr,index+1,end);
	}
}

int partition(int * arr,int start,int end)
{			
	//pick pivot as last element
	int pivot = arr[end];
	
	int index = start; //pivot index
	
	for(int i = start ;i <= end-1;i++) //loop through the array
	{
		if(arr[i] <= pivot) //divide the array w.r.t the pivot value.
		{
			std::swap (arr[i],arr[index]);
			index ++;
		}		
	}
	
	//place the pivot to its corrrect position
	std::swap(arr[index],arr[end]);
	
	return index; //return pivot position
}

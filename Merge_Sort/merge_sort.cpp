/**********************************************************************
*
*  FILE NAME	: merge_sort.cpp
*
*  DESCRIPTION  : Implementation of merge sort algorithm.
* 
*  PLATFORM		: Linux
***********************************************************************/

//header file inclusion
#include <iostream>

//function declaration
void merge_sort(int * arr,int len);
void sort(int *arr,int *temp,int leftstart,int rightend);
void merge(int *arr,int *temp,int leftstart,int rightend,int middle);

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
		
	//call merge sort
	merge_sort(digits,count);
	
	std::cout<<"The sorted list is :"<<std::endl;
	for(i=0;i<count;i++)
	{
		std::cout<<digits[i]<<std::endl;
	}
		
	delete []digits;
		
	return 0;
}

//function defination
void merge_sort(int * arr,int len)
{
	//allocate the temporary memory required 
	int *temp = new int[len];
	
	sort(arr,temp,0,len-1);
	
	//free the memory
	delete []temp;
}


void sort(int *arr,int *temp,int leftstart,int rightend)
{
	if(leftstart >= rightend)
		return;
		
	int middle = (leftstart + rightend)/2;
	
	sort(arr,temp,leftstart,middle);
	sort(arr,temp,middle+1,rightend);
	merge(arr,temp,leftstart,rightend,middle);
}

void merge(int *A,int *temp,int low,int high,int mid)
{
    int left, right, index;
    left = low;
    index = low;
    right = mid + 1;
    
    while (left <= mid && right <= high)
    {
        if (A[left] < A[right])
        {
            temp[index] = A[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = A[right];
            index++;
            right++;
        }
    }
    
    while (left <= mid)
    {
        temp[index] = A[left];
        index++;
        left++;
    }
    
    while (right <= high)
    {
        temp[index] = A[right];
        index++;
        right++;
    }
    
    for (int i = low; i < index; i++)
    {
        A[i] = temp[i];
    }
}

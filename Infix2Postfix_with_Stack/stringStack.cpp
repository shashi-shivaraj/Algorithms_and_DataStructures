#include <iostream>
using std::cout;
using std::endl;

#include <stdlib.h>

#include "stringStack.h"

void StringStack::push(const string& x) 
{
		if(top < 0)
		{
			top = 0;
			stack[top] = x;
			top ++;
		}
		else if(top < capacity)
		{
			stack[top] = x;
			top ++;
		}
		else
		{
			std::cout<<"Stack  is full"<<std::endl;
		}
}

string StringStack::pop() 
{
	if(top <= 0)
	{
		std::cout<< "Stack is empty"<<std::endl;
		return string("");
	}
	else
	{
	  string ele = stack[top-1];
	  stack[top-1].clear();
	  top --;
	  return ele;
	}
	 
}

string StringStack::topOfStack() 
{
	if(top <= 0)
	{
		std::cout<< "Stack is empty"<<std::endl;
		return string("");
	}
	else
	{
	  string ele = stack[top-1];
	  return ele;
	}
}

bool StringStack::isEmpty() 
{
	if(top <= 0)
	{
		std::cout<< "Stack is empty"<<std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

IntSet::IntSet()
{
  /* head pointing to NULL */
  head = NULL;
}

IntSet::~IntSet()
{
  Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

/* Return true if key is in the set */
bool IntSet::find(int key)
{
  Node *temp = head,*curr = NULL;
  while (temp != NULL) 
  {
    curr = temp;
    if(curr->key == key)
    {
		return true;
	}
    temp = temp->next;
  }
  
  return false; //key not found
}

/* Inserts a new key.  It is an error if key is already in the set. */
void IntSet::insert(int key)
{
  bool isLast = true;
   	
  if(find(key)) //key already present in the list
  return;
  
  //insert the node to the list to form a sorted linked list (in ascending order)
  if(!head)
  {
	  head = new Node(key,NULL);
  }
  else
  {
	   Node *temp = head,*curr = NULL,*prev = NULL;
	   Node *new_Node = NULL;
	   
		while (temp != NULL) 
		{	
			curr = temp;
			if(curr->key > key) //condition to insert
			{	
				if(curr == head)
				{
					new_Node = new Node(key, head);
					head = new_Node;
				}
				else
				{
					new_Node = new Node(key, curr);
					prev->next = new_Node;
				}
				isLast = false;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		
		if(isLast == true) //insert at end of the list
		{
			prev->next = new Node(key,NULL);
		}
	}
}

/* Removes a key.  It is an error if key isn't in the set */
void IntSet::remove(int key)
{
  if(!find(key)) //key not present in list
  return;
  
  Node *temp = head,*curr = NULL,*prev = NULL;
  while (temp != NULL) 
  {
    curr = temp;
    if(curr->key == key) //KEY FOUND
    {
		if(curr == head)
		{
			head = curr->next;
			temp = head;
		}
		else
		{
			prev->next = curr->next;
		}
		delete curr;
		return;
	}
	
	prev = temp;
    temp = temp->next;
  }
}

void IntSet::print(void)
{
	std::cout<<"The sorted list is : "<<std::endl;
	Node *temp = head,*curr = NULL;
	while (temp != NULL) 
	{
		curr = temp;
		std::cout <<curr->key<<"\t";
		temp = temp->next;
	}
	std::cout<<std::endl;
}

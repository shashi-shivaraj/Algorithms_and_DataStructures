#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include "intset.h"

// Inserts key into a tree represented by x.
Node* IntSet::insert (Node* x, int key) 
{
	if(!x) //allocate new node
	{
		return new Node (key,nullptr,nullptr);
	}
	else if(key > x->key) //go to right subtree
	{
		x->right = insert(x->right,key);
		x->right->parent = x; 
	}
	else //go to left subtree
	{
		x->left = insert(x->left,key);
		x->left->parent = x;
	}
	
	return x;
	
}

// This is a wrapper function that calls the actual insert routine. It is an error to call this function
// with a duplicate key.
void IntSet::insert (int key) 
{
  assert(!find(key));
  root = insert(root, key);
}

// Searches for key in tree represented by x.
Node* IntSet::find (Node *x, int key) 
{  
	if(!x)
	{
		return nullptr;
	}
	else if(key == x->key)
	{
		return x; //key found
	}
	else if(key > x->key)
	{
		find (x->right,key); //check right subtree
	}
	else
	{
		find (x->left,key); //check left subtree
	}
}

// This is a wrapper function that calls the actual find routine.
Node* IntSet::find (int key)
{
	return find (root, key);
}

// Performs an in-order traversal.
void IntSet::inOrder (Node *x) 
{
	if(!x)
	{
		return;
	}
	
	inOrder(x->left);
	std::cout<<x->key<<std::endl; //print the key 
	inOrder(x->right);
	
}

// This is a wrapper function that calls the inorder routine to enumerate contents of the set.
void IntSet::print() 
{
  inOrder(root);
  cout << endl;
}


//This is a wrapper function to delete the tree
void IntSet::deleteBST()
{
	deleteBST(root);
}


void IntSet::deleteBST(Node* x)
{
	if(!x)
		return;
		
	//post order traverasal
	deleteBST(x->left); //delete left subtree
	deleteBST(x->right); //delete right subtree
	
	delete x;
}

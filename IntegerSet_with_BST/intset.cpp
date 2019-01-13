#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include "intset.h"

// Inserts key into a tree represented by x.
Node* IntSet::insert (Node* x, int key) {
}

// This is a wrapper function that calls the actual insert routine. It is an error to call this function
// with a duplicate key.
void IntSet::insert (int key) {
  assert(!find(key));
  root = insert(root, key);
}

// Searches for key in tree represented by x.
Node* IntSet::find (Node *x, int key) {
}

// This is a wrapper function that calls the actual find routine.
Node* IntSet::find (int key) {
  return find (root, key);
}

// Performs an in-order traversal.
void IntSet::inOrder (Node *x) {
}

// This is a wrapper function that calls the inorder routine to enumerate contents of the set.
void IntSet::print() {
  inOrder(root);
  cout << endl;
}

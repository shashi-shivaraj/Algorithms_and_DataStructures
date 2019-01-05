#include <iostream>
#include <assert.h>
#include "intset.h"

using namespace std;

IntSet::IntSet()
{
  /* Start with dummy node */
  head = new Node(0, NULL);
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
}

/* Inserts a new key.  It is an error if key is already in the set. */
void IntSet::insert(int key)
{
  assert (!find(key));
}

/* Removes a key.  It is an error if key isn't in the set */
void IntSet::remove(int key)
{
  assert (find(key));
}

void IntSet::print(void)
{
}

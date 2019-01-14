#include <iostream>
#include <stdlib.h>

using namespace std;

#include "intset.h"

#define SIZE	10

int main() {
  IntSet s;
  int key;
  int arr[SIZE];
  int len = 0;

  while (cin >> key) {
    if (!s.find(key)) {
      s.insert(key);
      arr[len++] = key;
    }
  }
  cout << "Full list: "<<endl;
  s.print();		// Should print in sorted order

  //s.insert(key);	// Inserting a duplicate element. This is an error.

  return 0;
}

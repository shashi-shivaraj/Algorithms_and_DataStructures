#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring>
#include <string>
using std::string;

#define M 200 + 10			    // Always give more room than you need
#define N 200 + 10

unsigned short **mat;			// This is the bitmap repreentation in format B
string formatD;				    // This is the bitmap repreentation in format D
unsigned int ind;			// This is used to traverse format D

/* This function is used to convert a bitmap from format B to format D. The columns of this matrix are defined by
   startCol to endCol and the rows are defined by startRow to endRow. */
void convertBtoD (unsigned int startCol, unsigned int endCol, unsigned int startRow, unsigned int endRow) {
  // Your code here

  // Don't forget your base cases
}

/* This function is used to convert a bitmap from format B to format D. The columns of this matrix are defined by
   startCol to endCol and the rows are defined by startRow to endRow. */
void convertDtoB (unsigned int startCol, unsigned int endCol, unsigned int startRow, unsigned int endRow) {
  // Your code here

  // Don't forget your base cases
}

int main() {
  unsigned int rowSize, colSize;		// The row and column sizes of the bit map
  char format;					// The format we will convert from

  cin >> format >> rowSize >> colSize;
  mat = new unsigned short* [rowSize];	// Allocating space for the matrix and initializing with 0s.
  for (unsigned int i = 0; i < rowSize; ++i) {
    mat[i] = new unsigned short [colSize];
    memset(mat[i], 0, colSize);
  }

  if (format == 'B') {				// If format is B, we need to convert to D
    for (unsigned int i = 0; i < rowSize; ++i) // Get the format B input
      for (unsigned int j = 0; j < colSize; ++j)
        cin >> mat[i][j];

    formatD = "";
    convertBtoD (0, colSize, 0, rowSize);	// Convert to D
    cout << formatD << endl;			// Displaying results
  }
  else if (format == 'D') {			// If format is D, we need to convert to B
    cin >> formatD;				// Get the format D input
    ind = 0;
    convertDtoB (0, colSize, 0, rowSize);	// Convert to B
    for (unsigned int i = 0; i < rowSize; ++i) { // Displaying results
      for (unsigned int j = 0; j < colSize; ++j)
        cout << mat[i][j] << " ";
      cout << endl;
    }
  }
  return 0;
}

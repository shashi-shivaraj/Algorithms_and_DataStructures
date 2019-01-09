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
void convertBtoD (unsigned int startCol, unsigned int endCol, unsigned int startRow, unsigned int endRow) 
{
	//std::cout<< "StartCol " <<  startCol << " endCol "<< endCol << " startRow " << startRow << " endRow " << endRow<<std::endl;	
	int r=0,c=0;
	unsigned short first_val = 0;
	bool isDiff = false;
	
	//check if all the elements in the matrix is same
	for(r = startRow;r < endRow;r++)
	{
		for(c = startCol; c < endCol;c++)
		{
			if(r == startRow && c == startCol)
				first_val = mat[r][c];
				
			if(first_val != mat[r][c])
			{
				isDiff = true;
				break;		
			}
		}
	}
	
	if(isDiff == false)
	{
		if(first_val == 0)
		{
			//std::cout<< "appending 0 "<<std::endl;
			formatD.append("0");
		}
		else if(first_val == 1)
		{
			//std::cout<< "appending 1 "<<std::endl;
			formatD.append("1");
		}
	}
	else
	{
		//std::cout<< "appending D "<<std::endl;
		formatD.append("D");
		int quad_row_size = (endRow - startRow)/2;
		int quad_col_size = (endCol - startCol)/2;
		
		//Recursively compute format D representation of the top-left quadrant.
		convertBtoD (startCol,startCol+quad_col_size,startRow,startRow+quad_row_size);
		//Recursively compute format D representation of the top-right quadrant.
		convertBtoD (startCol + quad_col_size,endCol,startRow,startRow+quad_row_size);
		//Recursively compute format D representation of the bottom-left quadrant.
		convertBtoD (startCol,startCol+quad_col_size,startRow+quad_row_size,endRow);
		//Recursively compute format D representation of the bottom-right quadrant.
		convertBtoD (startCol+quad_col_size,endCol,startRow+quad_row_size,endRow);
	}
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

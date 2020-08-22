/*Given a matrix A, return the transpose of A.
The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) 
    {
        int rows = A.size();
        int cols = A[0].size();
        
       vector<vector<int>> B(cols, vector<int>(rows, 0));
                
        for(int i = 0; i < cols; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                
                B[i][j] = A[j][i];
            }
        }
        
        return B;
    }
};
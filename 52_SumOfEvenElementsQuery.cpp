/*
We have an array A of integers, and an array queries of queries.
For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].
Then, the answer to the i-th query is the sum of the even values of A.
(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)
Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.

Example 1:
Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: 
At the beginning, the array is [1,2,3,4].
After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
*/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) 
    {
        int val = 0;
        int index = 0;
        
        int evenSum = 0;
        
        for(int i : A) //loop through A and find the sum of even elements
        {
            if(!(i%2))
            {
                evenSum += i;
            }
        }
        
        vector<int> *ans = new vector<int>(queries.size());
        
        for(int i = 0;i < queries.size() ; i++) //loop through the queries
        {
            val = queries[i][0];
            index = queries[i][1];
            
            if(!(A[index]%2)) //if its even delete it from sum
            {
                evenSum -= A[index];
            }
            
             A[index] += val;   //add it to the element at index
                
            if(!(A[index]%2)) //check if updated element is even
            {
                 evenSum += A[index]; //update the sum
            }  
            
            (*ans)[i] = evenSum; //add it to result
        }
        
        return *ans;
    }
};
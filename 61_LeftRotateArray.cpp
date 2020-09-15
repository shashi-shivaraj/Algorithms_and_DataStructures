/* Given an array, rotate the array to the left by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [4,5,6,7,1,2,3]
Explanation:
rotate 1 steps to the left: [2,3,4,5,6,7,1]
rotate 2 steps to the left: [3,4,5,6,7,1,2]
rotate 3 steps to the left: [4,5,6,7,1,2,3]

Sol: 
nums = [1,2,3,4,5,6,7], k = 3
[7,6,5,4,3,2,1] //reverse entire array
[4,5,6,7,3,2,1] //reverse first [arr.size() - k] elements
[4,5,6,7,1,2,3] //reverse remaining elements
*/

class Solution {
public:
    
    void reverse(vector<int>& arr, int startIndex, int endIndex)
    {
        while(startIndex<endIndex)
        {
            std::swap(arr[startIndex], arr[endIndex]);
            startIndex++;
            endIndex--;
        }
    }
    
    vector<int> rotateLeft(int d, vector<int> arr) 
    {
        d = d % arr.size();

        reverse(arr, 0, arr.size()-1); //reverse entire array
        reverse(arr, 0, arr.size()-1-d); //reverse first [arr.size() - k] elements
        reverse(arr,arr.size()-d, arr.size()-1); //reverse remaining elements
    
        return arr;
    }
};
/* Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Sol: 
nums = [1,2,3,4,5,6,7], k = 3
[7,6,5,4,3,2,1] //reverse entire array
[5,6,7,4,3,2,1] //reverse first k elements
[5,6,7,1,2,3,4] //reverse remaining elements

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
    
    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size();
        
        reverse(nums,0, nums.size()-1); //reverse entire array
        reverse(nums,0, k-1); // reverse first k elements
        reverse(nums,k, nums.size()-1); //reverse remaining elements
    }
};
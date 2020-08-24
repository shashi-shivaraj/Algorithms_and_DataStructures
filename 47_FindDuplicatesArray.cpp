/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        int index = 0;
        
        if(!nums.size() || nums.size() == 1)
            return ans;
        
        for(int i = 0 ; i < nums.size(); i++) //loop through the vector
        {
            int index = std::abs(nums[i])-1; //use value as index and change the value at index to negative
            
            if(nums[index] < 0) //if its already negative then the index value is duplicate
            {
                ans.push_back(std::abs(nums[i]));
            }
            else
            {
                nums[index] = - nums[index]; //change the value at index to negative
            }
        }
        
        return ans;
    }
};
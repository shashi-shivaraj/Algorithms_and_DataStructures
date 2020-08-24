/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans = {-1,-1};
        
        ans[0] = BinarySearchStartIndex(nums,target);
        ans[1] = BinarySearchStopIndex(nums,target);
        
        return ans;
    }
        
    int BinarySearchStartIndex(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int index = -1;
         
        while(left <= right)
        {
            mid = left + ((right-left)/2);
            
            if(nums[mid] >= target) //modify to find the left most index if duplicates exits
            {
                right = mid - 1;
                
            }
            else
            {
                left = mid + 1;
            }
            
            if(nums[mid] == target)
            {
                index = mid; 
            }
        }
        
        return index;
    }
    
    int BinarySearchStopIndex(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() -1;
        int mid;
        int index = -1;
         
        while(left <= right)
        {
            mid = left + ((right-left)/2);
            
            if(nums[mid] <= target) //modify to find the right most index if duplicates exits
            {
                left = mid + 1;
                
            }
            else
            {
                right = mid - 1;
            }
            
            if(nums[mid] == target)
            {
                index = mid; 
            }
        }   
        return index;
    }   
};
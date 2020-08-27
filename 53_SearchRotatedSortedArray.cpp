/*Given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You should search for target in nums and if you found return its index, otherwise return -1.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if(!nums.size())
            return -1;
        
        int left = 0;
        int right = nums.size() -1;
        int mid = 0;
         
        while(left < right) //modified binary search to find the min in rotated array
        {
            mid = left + (right -left)/2;
            
            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        int lowest_index = left; //min will be left
        std::cout<<lowest_index<<std::endl;
        
        if(target >= nums[lowest_index] && target <= nums[nums.size() -1]) //check the target location range
        {
            left = lowest_index;
            right = nums.size() -1;
        }
        else
        {
            left = 0;
            right = lowest_index - 1;
        }
        
        while(left <= right) //normal binary search to find the target
        {
            mid = left + (right - left)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
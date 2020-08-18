/*
Suppose an array sorted in ascending order is rotated 
at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2] 
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0
*/

/*O(N) solution*/

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int min = nums[0];
        
        for(int i = 0 ;i < nums.size() -1 ;i++)
        {
            if(nums[i] > nums[i+1])
            {
                return nums[i+1];
            }
        }
        
        return min;
    }
};

/*O(logN) Binary search solution */
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int count = nums.size();
        
        if(count == 1 || nums[0] < nums[count-1]) //check the ends if its not rotated or single element
            return nums[0];
        
        //its rotated
        int left = 0; 
        int right = count-1;
        
        //Binary search
        while(right >= left)
        {
            int mid = (right + left)/2;
            
            if(nums[mid] > nums[mid + 1]) //point of rotation
            {
                return nums[mid+1];
            }
            
            if(nums[mid-1] > nums[mid]) //point of rotation
            {
                return nums[mid];
            }
            
            if(nums[mid] > nums[0]) //mid is currently at left of point of rotation
            {
                left = mid + 1;
            }
            else    //mid is currently at right of point of rotation
            {
                right = mid -1;    
            }
        }
        return nums[0];   
    }
};

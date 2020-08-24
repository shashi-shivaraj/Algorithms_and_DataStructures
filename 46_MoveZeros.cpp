/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;
        int j = 0;
        int count = nums.size();
        
        while(i < count && j < count)
        {
            if(!nums[i])
            {
                while(j < count && !nums[j])
                {
                    j++;
                }
                
                if(j < count)
                    std::swap(nums[i],nums[j]);
                else
                    return;
            }
            
            i++;
            j++;
        }
    }
};

void moveZeroes(vector<int>& nums)  // move the non-zero elements to front.
{
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) 
    {
        if (nums[cur] != 0) 
        {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}
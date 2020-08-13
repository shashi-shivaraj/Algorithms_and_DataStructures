/*Given a sorted array nums,
remove the duplicates in-place such that each element appear only once
and return the new length.Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.*/

class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {   
            int count = nums.size();
            
            if(!count) 
                return 0;

            int pos = 0;
            for(int i = 1; i < count;i++)
            {
                if(nums[pos] == nums[i])
                    continue;
                
                pos ++;
                    
                nums[pos] = nums[i];
            }
                
            return pos+1;
        }
};
/*Given a non-empty array of integers,
every element appears twice except for one.
Find that single one.*/

class Solution 
{
    public:
  
        int singleNumber(vector<int>& nums) 
        {
            int num = 0;
            
            for(int i : nums)
            {
                num ^= i;
            }
            
            return num;
        }
};
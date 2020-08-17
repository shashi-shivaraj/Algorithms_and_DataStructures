/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        std::map<int,int> count;
        
        for(int i : nums)
        {
            if(count.find(i) != count.end())
            {
                count[i] ++;
            }
            else
            {
                count.insert(std::make_pair(i,1));
            }
        }
        
        int max = (*count.begin()).first;
        int max_count = (*count.begin()).second;
        
        for(auto it = count.begin();it != count.end();it++)
        {
            if((*it).second > max_count)
            {
                max_count = (*it).second;
                max = (*it).first;
            }
        }
        
        return max;
        
    }
};
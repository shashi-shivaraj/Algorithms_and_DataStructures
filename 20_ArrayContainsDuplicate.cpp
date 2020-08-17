/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if(!nums.size() || nums.size() == 1)
            return false;
        
        std::sort(nums.begin(),nums.end()); //sort the vector
        
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1]) //check adjacent elements
                return true;
        }
        
        return false;
    }
};

//other approach, maintain a set

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if(!nums.size() || nums.size() == 1)
            return false;
        
      std::set<int> setNums;
        
        for(int i = 0;i < nums.size();i++)
        {
            if(setNums.find(nums[i]) != setNums.end())
                return true;
            else
                setNums.insert(nums[i]);
        }
        
        return false;
    }
};
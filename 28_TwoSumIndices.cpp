/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*Hash map method*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<int> res;
        std::map<int,int> Map;
     
        for(int i = 0 ; i < nums.size() ;i ++) //loop through the array
        {
            int compliment = target - nums[i];
            
            if(Map.find(compliment) != Map.end()) //check if the other pair already exists
            {
                res.push_back(i);
                res.push_back(Map[compliment]);
                return res;
            }
            
            Map.insert({nums[i],i}); //insert the number with index
        }
        
        return res;
    }
};

/*O(NxN) solution using loops*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
     
        for(int i = 0 ; i < nums.size() ;i ++)
        {
            for(int j = 0; j < nums.size();j++)
            {
                if(i != j && nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        
        return res;
    }
};
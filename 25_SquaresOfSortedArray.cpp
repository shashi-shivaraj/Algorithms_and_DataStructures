/*
Given an array of integers A sorted in non-decreasing order,
return an array of the squares of each number,
also in sorted non-decreasing order.

Example 1:
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> res(nums.size());
        
        if(nums[0] >= 0) //check if the array contains only positive numbers
        {
            int j = 0;
            for(int i : nums)
            {
                res[j] = i * i;
                j ++;
            }
        }
        else //array contains negative numbers 
        {
            int posPosition = 0;
            
            for(int i : nums) //find the index of first non-negative number
            {
                if(i >= 0)
                    break;
                
                posPosition ++;
            }
            
            int index = 0; 
            int negIndex = posPosition-1; //move backwards in increasing direction of abs val of negative numbers
            int posIndex = posPosition; //move forward in increasing direction
            
            while(negIndex >= 0 && posIndex < nums.size()) //compare the two sorted sections and insert
            {   
                if(std::abs(nums[negIndex]) < nums[posIndex])
                {
                    res[index] = (nums[negIndex] * nums[negIndex]);
                    negIndex --;   
                }
                else
                {
                    res[index] = (nums[posIndex] * nums[posIndex]);
                    posIndex ++;
                }
                
                index++;
            }
            
            while(posIndex < nums.size()) //check if end of positive numbers is reached
            {
                res[index] = (nums[posIndex] * nums[posIndex]);
                posIndex ++;
                index++;
            }
            
            while(negIndex >= 0) //check if end of negative numbers is reached
            {
                res[index] = (nums[negIndex] * nums[negIndex]);
                negIndex --;
                index++;
            }
        }      
        return res;
    }
};
/*
Given a non-empty array of digits representing a non-negative integer,
increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list,
and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero,
except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [9,9,9,9]
Output: [1,0,0,0,0]
Explanation: The array represents the integer 10000.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for(auto it = digits.end()-1 ;it >= digits.begin() ; it--)
        {   
            if(*it + 1 < 10) //check for carry-over after adding 1 
            {
                (*it)++;    
                
                return digits; //no carry-over exit
            }
            
            *it = 0; //set to zero add carry -over 1 to next msb
        }
        
        if(!digits.front()) //check msb is zero
        {
            digits.insert(digits.begin(),1); //insert carry-over
        }
        
        return digits;
    }
};
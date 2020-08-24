/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/

//O(2*n) = O(N)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> ans;
        
        int index = 0;
        for(int i = 0; i < nums.size() ; i++) //loop through the numbers and use them as indices
        {
            int index = std::abs(nums[i]) - 1;
            
            if(nums[index] > 0)
                nums[index] = - nums[index]; //negate the value if its positive
        }        
        
        for(int i = 0; i < nums.size() ; i++) //loop through the vector
        {
            if(nums[i] > 0) //if the element is positive, then the its index in not in the vector 
            {
                ans.push_back(i+1);
            }
                
        }
        
        return ans;
    }
};
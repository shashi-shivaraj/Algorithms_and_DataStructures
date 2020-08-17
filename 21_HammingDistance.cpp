/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Input: x = 1, y = 4
Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

*/

class Solution {
public:
    int hammingDistance(int x, int y) 
    {   
        x = x ^ y; //same bits will be set to 0 and different bits will be set to 1
        
        y = 0;
        
        while(x) //count number of bits set to 1
        {
            y++;
            x = x & x-1;    //will set the first LSB bit = 1 to 0
        }
        
        return y;
    }
};
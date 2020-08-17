/*Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.*/

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int res = 0;
        
        while(n)
        {
            if(n & 1)
            {
                res ++;
            }
            
            n >>= 1;
        }
        
        return res;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int res = 0;
        
        while(n)
        {
            res++;
            n &= (n - 1); //ANDing the two numbers n and n - 1 always flips the least significant 1-bit in n to 0, and keeps all other bits the same
        }
        
        return res;
    }
};
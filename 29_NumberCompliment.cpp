/*
Given a positive integer num, output its complement number.
The complement strategy is to flip the bits of its binary representation.

Example 1:
Input: 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Example 2:
Input: 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
*/
class Solution {
public:
    int bitwiseComplement(int N) 
    {
        if(!N)
            return 1;
        
        int res = N;
        int count = 0;
        
        while(N)
        {
            res = res ^ (1<<count); //xor each bit with 1 to flip the bits.
            N = N >> 1;
            
            count ++;
        }

        return res;
    }
};
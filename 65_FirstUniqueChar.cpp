/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.
s = "loveleetcode"
return 2.
 
Note: You may assume the string contains only lowercase English letters.
*/
class Solution {
public:
    int firstUniqChar(string s) 
    {
        std::map<char,int> mapC;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(mapC.find(s[i]) == mapC.end())
            {
                mapC.insert({s[i], 1});
            }
            else
            {
                mapC[s[i]] ++;
            }
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(mapC[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};
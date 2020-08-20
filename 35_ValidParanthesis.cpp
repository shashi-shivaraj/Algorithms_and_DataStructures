/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false
*/
class Solution {
public:
    bool isValid(string s) 
    {   
        if(!s.size())
            return true;
        
        std::map<char, char> map = {{']','['},{')','('},{'}','{'}};
        
        std::stack<char> stackB;
        
        for(int i = 0; i < s.size();i++)
        {
            if(map.find(s[i]) != map.end()) //its a closing right bracket
            {
                if(stackB.empty() || stackB.top() != map[s[i]])
                {
                    return false;
                }
                else
                {
                    stackB.pop();   
                }
            }
            else //its left bracket
            {
                stackB.push(s[i]);
            }
        }
        
        return stackB.empty();
    }
};
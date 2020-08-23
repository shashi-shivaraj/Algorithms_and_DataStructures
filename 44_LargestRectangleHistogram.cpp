/*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 find the area of largest rectangle in the histogram.

Example:
Input: [2,1,5,6,2,3]
Output: 10

Example:
Input: [1,1,1,1,1]
Output: 5
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if(!heights.size())
            return 0;
        
        int max_area = -1;
        int area = -1;
        
        std::stack<int> Pstack; //stack to store the index
        
        for(int i = 0; i < heights.size(); i++)
        {
            while(!Pstack.empty() && heights[i] < heights[Pstack.top()]) //top of the stack should have the lowest height
            {
                int top_index = Pstack.top();
                Pstack.pop(); //remove from stack
                
                area = heights[top_index] * (Pstack.empty()?i:(i-Pstack.top()-1)); //height*current index from origin/current top
                
                if(area > max_area)
                    max_area = area;
            }
            Pstack.push(i); //add to stack
        }
        
        while(!Pstack.empty()) //stack should be empty.
        {
            int top_index = Pstack.top();
            Pstack.pop();
            
            area = heights[top_index] * (Pstack.empty()?heights.size():(heights.size()-Pstack.top()-1));//height*index from origin/current top
            
            if(area > max_area)
                max_area = area;              
        }
        
        return max_area;
    }
};
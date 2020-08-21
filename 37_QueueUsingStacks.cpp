/*Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.

Example:
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        newAtTop.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int ret = -1;
        
        cleanupNewAtTop();
        
        if(!oldAtTop.empty())
        {
            ret = oldAtTop.top();
            oldAtTop.pop();
        }
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() 
    {
        int ret = -1;
        
        cleanupNewAtTop();
        
        if(!oldAtTop.empty())
        {
             ret = oldAtTop.top();
        }
        
        return ret;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {   
        cleanupNewAtTop();
        return oldAtTop.empty();
    }
    
private:
    std::stack<int> newAtTop;
    std::stack<int> oldAtTop;
    
    void cleanupNewAtTop()
    {
        if(oldAtTop.empty())
        {
            while(!newAtTop.empty())
            {
                oldAtTop.push(newAtTop.top());
                newAtTop.pop();
            }
        }
    }
};
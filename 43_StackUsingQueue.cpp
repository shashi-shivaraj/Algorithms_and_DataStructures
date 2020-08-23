/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {   
        inputQ.push(x);
        int size = inputQ.size();
        
        while(size >1) //move last element to front of queue for stack
        {
            inputQ.push(inputQ.front());
            inputQ.pop();
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int res = inputQ.front();
        inputQ.pop();
        
        return res;
        
    }
    
    /** Get the top element. */
    int top() 
    {
        return inputQ.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return (inputQ.empty());
    }
    
private:
    std::queue<int> inputQ;
    int topval;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
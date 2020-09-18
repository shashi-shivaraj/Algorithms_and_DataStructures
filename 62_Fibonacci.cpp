/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

Ex:
0, 1, 1, 2, 3, 5, 8, 13, 21 ..........
*/

//recursive solution 
class Solution {
public:
    int fib(int N) 
    {   
        if (N <= 1) 
        {
            return N;
        }
        
        return fib(N-1) + fib(N-2);
    }
};

//memoised recursive solution
class Solution {
public:
    int fib(int N) 
    {   
        int *arr = new int[N+1];
        
        for(int i = 0; i < N+1;i++)
        {
            arr[i] = 0;
        }
        
        return fibMem(N, arr);
    }
    
    int fibMem(int N, int *arr)
    {
        if(arr[N])
            return arr[N];
        
        int res = 0;
        
        if(N <= 1)
            res = N;
        else
            res = fibMem(N-1, arr) + fibMem(N-2, arr); 
        
        arr[N] = res;
        
        return res;
    }
};

//bottom-up solution
class Solution {
public:
    int fib(int N) 
    {   
        if(N <= 1)
            return N;    
        
        int *arr = new int[N+1];
        arr[0] = 0;
        arr[1] = 1;
        
        for(int i = 2; i < N+1;i++)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
        
        return arr[N];
    }
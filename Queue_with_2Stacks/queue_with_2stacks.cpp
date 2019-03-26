//Program to create a queue using two stacks

//header file inlcusion
#include <iostream>
#include <stack>

//class declaration
class Queue_SS
{
	public:
		void insert(const int &data);
		int remove(int &data);
	
	private:
		std::stack<int> S_one;
		std::stack<int> S_two; 
};


//main function of the program
int main()
{
	Queue_SS Queue; 
	int data = 0;
	int ret = 0;
	
	std::cout<<"Enqueue 1"<<std::endl;
	Queue.insert(1);
	std::cout<<"Enqueue 2"<<std::endl;
	Queue.insert(2);
	std::cout<<"Enqueue 3"<<std::endl;
	Queue.insert(3);
	std::cout<<"Enqueue 4"<<std::endl;
	Queue.insert(4);
	
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	
	std::cout<<"Enqueue 1"<<std::endl;
	Queue.insert(1);
	std::cout<<"Enqueue 2"<<std::endl;
	Queue.insert(2);
	
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	
	std::cout<<"Enqueue 3"<<std::endl;
	Queue.insert(3);
	
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	
	std::cout<<"Enqueue 4"<<std::endl;
	Queue.insert(4);
	
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	
	ret = Queue.remove(data);
	std::cout<<"Dequeue returns data = "<<data<<" err = "<<ret<<std::endl;
	
		
	return 0;
} 

//class definations
void Queue_SS::insert(const int &data)
{
	S_one.push(data);
}


int Queue_SS::remove(int &data)
{
	int ret = 0;
	
	if(!S_two.size() && S_one.size())
	{
		while(S_one.size())
		{
			S_two.push(S_one.top());
			S_one.pop();
		}
	}
	
	if(S_two.size())
	{
		data = S_two.top();
		S_two.pop();
		return 0;
	}
	else
		return -1; //error to notify queue is empty
}

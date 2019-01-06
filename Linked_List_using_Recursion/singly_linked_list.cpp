//Program to create a linked list and perform 
//operations on it using recursion

//header file inlcusion
#include <iostream>

//class declaration
class node
{
	friend class LL_manager;
	
public:
	node();
	~node();
	node(int k,node *n);
	 
private:
	int key;
	node *next;
};

class LL_manager
{
	private:
		node * head;
		node * insert(int k,node* start);
		node * sort(node *L);
		node * reverse(node *L);
		void printlist(node *L);
		int getLength(node *start);
		
	public:
		LL_manager(int len);
		~LL_manager();
		int getListLength();
		void printLL();
		void sorted_insert(int k);
		void sort_list();
		void reverse_list();
};

//create a random list
node * create_list(int len)
{
	if (!len)
		return NULL;
		
	return new node(rand() % 100,create_list(len-1));
}

//main function of the program
int main()
{
	
	const int len = 10;
	
	//create list with random number
	LL_manager list(len);

	//get length of the list
	std::cout<<"length of the List = "<<list.getListLength()<<std::endl;
	
	//print the list
	std::cout<<" The List is = "<<std::endl;
	list.printLL();
	
	//sort the list
	list.sort_list();
	
	//print the list
	std::cout<<" The sorted List is = "<<std::endl;
	list.printLL();
	
	//reverse the list
	list.reverse_list();
	std::cout<<" The reversed List is = "<<std::endl;
	list.printLL();
	
	return 0;
} 

//class definations
LL_manager::LL_manager(int len)
{
	head = create_list(len);
}

LL_manager::~LL_manager()
{
	node *cur = NULL;
	while(head)
	{
		cur = head;
		delete cur;
		head = head->next;
	}
}

//wrapper to get length
int LL_manager::getListLength()
{
	return getLength(head);
}

int LL_manager::getLength(node *start)
{
	if(!start)
		return 0;
	else
		return 1 + getLength(start->next);
}

//wrapper to insert in sorted order
void LL_manager::sorted_insert(int k)
{
	head = insert(k,head);
}

void LL_manager::sort_list()
{
	head  = sort(head);
}

//wrapper to print the list
void LL_manager::printLL()
{
	printlist(head);
}


void LL_manager::printlist(node *L)
{
	if(!L)
	 return;
	
	std::cout<<L->key<<std::endl;
	printlist(L->next);
}


//wrapper to reverse the list
void LL_manager::reverse_list()
{
	head = reverse(head);
}

node* LL_manager::reverse(node *L)
{
	if(!L ||!L->next )
		return L;
		
	node * second = L->next;
	node * last = reverse(L->next);
	second->next = L;
	L->next = NULL;
	
	return last;
}

node* LL_manager::sort(node *L)
{
	if(!L)
		return L;
		
	return insert(L->key,sort(L->next)) ;
	
}


node* LL_manager::insert(int k,node* start)
{
	if(!start || start->key > k)
		return new node(k,start);
	
	start->next = insert(k,start->next);
	return start;
}
		
node::node()
{
	key = 0;
	next = NULL;
}

node::~node()
{
	
}

node::node(int k,node *n)
{
	key = k;
	next = n;
}

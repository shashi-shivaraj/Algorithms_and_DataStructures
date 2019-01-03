// Program to find the max cylce length of 
// of 3n+1 algorithm an integers between a 
// range. 

//header file inclusion
#include <iostream>

//class declaration
class Collatz
{
	public:
	Collatz();
	Collatz(int min,int max);
	~Collatz();
	void GetMaxCyclelen(int &num,unsigned long long &len);
	
	private:
		int min_range;
		int max_range;
		const int mem_limit = 1000000;

		void three_n_plus_one_Algo(unsigned long long seed);
		unsigned long long cycle_len;
		unsigned long long *cycle_len_data;
};


//main function of the program
int main(int argc,char *argv[])
{
	int ret = -1;
	int min = 0,max = 0;
	int num = 0; 
	unsigned long long len = 0;
	
	//check for valid args
	if(argc != 3)
	{
		std::cout<<"[Usage]./exe min max"<<std::endl;
		return -1;
	}
	
	min = std::atoi(argv[1]);
	max = std::atoi(argv[2]);
	
	if(min > max)
	{
		std::cout << "[Usage]./exe min max"<<std::endl;
		return -1;
	}
	
	Collatz object(min,max);
	object.GetMaxCyclelen(num,len);
	
	std::cout <<"[Result] Number = "<<num<<" Max Cycle len = "<<len<< std::endl;
	
	return ret;
}

//class definations

//default constructor
Collatz::Collatz()
{

}

//constructor overload
Collatz::Collatz(int min,int max)
{
	min_range = min;
	max_range = max;
	
	cycle_len_data = new unsigned long long[mem_limit];
	if(!cycle_len_data)
		std::cout << "memory allocation failed" << std::endl;
}


Collatz::~Collatz()
{
	if(cycle_len_data)
	 delete cycle_len_data;
}


void Collatz::GetMaxCyclelen(int &num,unsigned long long &len)
{
	int i = 0;
	int max_num = 0;
	unsigned long long max_len = 0;
	
	for(i=min_range;i<=max_range;i++)
	{
		cycle_len = 0;
		three_n_plus_one_Algo(i);
		if(max_len < cycle_len)
		{
			max_len = cycle_len;
			max_num  = i;
		}
		cycle_len_data[i] = cycle_len;
	}
	
	num = max_num;
	len = max_len;
}

void Collatz::three_n_plus_one_Algo(unsigned long long seed)
{
	cycle_len ++;
	
	if(seed == 1)
	return;
	
	if(!(seed % 2))
		seed = seed / 2;
	else
		seed = 3*seed + 1;
	
	if(seed < mem_limit && cycle_len_data[seed])
	{
		cycle_len = cycle_len + cycle_len_data[seed];
	}
	else
	{		
		three_n_plus_one_Algo(seed);
	}
}

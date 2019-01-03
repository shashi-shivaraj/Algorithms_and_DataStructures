//Program to  find number of H->L and L-H transitions

//header file inlcusions
#include <iostream>

//main function of the program
int main(int argc,char* argv[])
{
	int ret = 0;
	int low_jmps = 0,high_jmps = 0;
	int height = 0;
		
	//check for valid args
	if(argc < 2)
	{
		std::cout<<"[Usage]./exe h_1 h_2 .....h_n"<<std::endl;
		return -1;
	}
	
	//init height
	height = std::atoi(argv[1]);
	//calculate the number of transitions
	for(int i = 2;i < argc;i++)
	{
		if(height < std::atoi(argv[i]))
		{
			high_jmps ++;
		}
		else if(height > std::atoi(argv[i]))
		{
			low_jmps ++;
		}
		
		height = std::atoi(argv[i]);
	}
	
	//display the output
	std::cout<<"[Result: LJ HJ] = "<<low_jmps<<" "<<high_jmps<<std::endl;
	
	return ret;
}

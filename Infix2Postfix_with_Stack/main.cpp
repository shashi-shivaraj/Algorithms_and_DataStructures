#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "stringStack.h"

//operator overload 

string operator+(const string &one ,const string &two)
{
	string res;
	res.append(one);
	res.append(two);
	
	return res;
}

// Gives the next token in the expr. 
string getToken(const string expr, int& index) {
  if (index >= expr.length()) return string("");

  // convert a string to a char *
  char * cstr;
  cstr = new char [expr.size()+1];
  strcpy (cstr, expr.c_str());

  // Tokenize, i.e., break up one line into its component tokens
  char * token;             // will hold one token from expr

  token = strtok(cstr + index, " \n");

  // Adding up index - can be used in next call
  index += string(token).length() + 1;

  if (token == NULL) return string("");
  return token;
}

// Returns true if token is an operand
bool isOperand(string token) {
  if (token.length() == 0)
    return false;
  for (int i = 0; i < token.length(); ++i) {
    if (token[i] < '0' || token[i] > '9')
      return false;
  }
  return true;
}

// Returns true if token is any of the operators ( ) * / % + -
bool isOperator(string token) {
  if (token == "(" || token == ")" || token == "*" || token == "/" || token == "%" || token == "+" || token == "-")
    return true;
  return false;
}

int getPool(string x) {
  if (x == "(") return 0;
  if (x == "+" || x == "-") return 1;
  if (x == "*" || x == "/" || x == "%") return 2;
  if (x == ")") return 3;
}
// returns the difference between the precedance of x and y. That is returns an integer > 0, if x is higher than y,
// < 0, if x is lower than y and 0 if x is equal in precedance to y. The function assumes x and y are valid operators.
int precedance(string x, string y) {
  int xpool = getPool(x);
  int ypool = getPool(y);
  return xpool - ypool;
}

// Convert the input string infix to postfix and return the postfix expression
string infixToPostfix(string infix) {
  int ind = 0;
  int left_brace_count = 0,right_brace_count = 0;
  bool opFlag = false;  /*set to true if current token is arithmetic operator*/
  string token;
  string postfix("");

  // This is your stringStack object
  StringStack operStack(infix.length());

  token = getToken(infix, ind);
  while (token != string("")) {
    cout << "processing token " << token << endl;	// The next token is available. Now just process this token.

    if(isOperand(token)) //if the token is an operand, write it to the postfix expression.
    {
		std::cout<<"wrinting to postfix: "<< token <<std::endl;
		token = token + " ";
		postfix = postfix + token;
		opFlag = false;
	}
	else if(isOperator(token))
	{
		
		//set opflag 
		if(token.compare("(") && token.compare(")"))
		{
			opFlag = true; // set to true,next token must end with operand
		}
		
		if(!token.compare("("))//(b) else if the operator is a (, then push it into the stack
		{
			std::cout<<"pushing to stack: "<<token<<std::endl;
			operStack.push(token);
			left_brace_count ++ ;
		}
		else if(operStack.isEmpty()) //(a) if the stack is empty, push the operator into stack.
		{
			std::cout<<"pushing to stack: "<<token<<std::endl;
			operStack.push(token);
		}
		else if(!token.compare(")")) //(c) else if the operator is a ), then pop all operators from the stack and write to postfix expression until a (. 				 
		{
			right_brace_count ++;
			while(operStack.isEmpty() == false && operStack.topOfStack() != "(")
			{
				std::cout<<"poping from stack "<<operStack.topOfStack()<<std::endl;
				postfix = postfix + operStack.pop() + " ";
			}
			std::cout<<"poping from stack "<<operStack.topOfStack()<<std::endl;
			operStack.pop();//Pop ( from the stack.
		}
		else
		{
			//i. while the top of stack has higher or equal precedence than the input token.
			//A. pop the top of stack and write it to the postfix expression.
			while(operStack.isEmpty() == false && (precedance(operStack.topOfStack(),token) >= 0))
			{
				std::cout<<"poping from stack "<<operStack.topOfStack()<<std::endl;
				postfix = postfix + operStack.pop() + " ";
			}
			
			//ii. push token into stack.
			std::cout<<"pushing to stack: "<<token<<std::endl;
			operStack.push(token);
		}	
	}
	
    token = getToken(infix, ind);
  }
  
  if(left_brace_count != right_brace_count)
  {
	  if(left_brace_count > right_brace_count)
	  {
		  std::cout<<"[ERROR]Missing right braces"<<std::endl; 
	  }
	  else
	  {
		  std::cout<<"[ERROR]Missing left braces"<<std::endl;
	  }
	  
	  return string("");
  }
  
  if(opFlag == true)
  {
	  std::cout<<"[ERROR]invalid expression"<<std::endl;
	  return string("");
  }
  
  while(operStack.isEmpty() == false) //Pop all the remaining items in stack and write to postfix expression.
  {
	std::cout<<"poping from stack "<<operStack.topOfStack()<<std::endl;
	postfix = postfix + operStack.pop() + " ";
  }

  return postfix;
}

int main() {
  string expr;
  string postfix;

  getline(cin, expr);
  cout << "Infix expression: " << expr << endl;

  postfix = infixToPostfix(expr);
  cout << "Postfix expression: " << postfix << endl;

  return 0;
}

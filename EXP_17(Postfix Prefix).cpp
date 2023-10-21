#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

	stack<string> s;
	// length of expression
	int length = pre_exp.size();

	// reading from right to left
	for (int i = length - 1; i >= 0; i--) 
	{
		// check if symbol is operator
		if (isOperator(pre_exp[i]))
		{
			// pop two operands from stack
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			// concat the operands and operator
			string temp = op1 + op2 + pre_exp[i];

			// Push string temp back to stack
			s.push(temp);
		}

		// if symbol is an operand
		else {

			// push the operand to the stack
			s.push(string(1, pre_exp[i]));
		}
	}

	// stack contains only the Postfix expression
	return s.top();
}

// Driver Code
int main()
{
	string pre_exp = "*-A/BC-/AKL";
	cout << "Postfix : " << preToPost(pre_exp);
	return 0;
}
//PREFIX
// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
	// If the character is a digit then it must
	// be an operand
	return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
	stack<double> Stack;

	for (int j = exprsn.size() - 1; j >= 0; j--) {

		// Push operand to Stack
		// To convert exprsn[j] to digit subtract
		// '0' from exprsn[j].
		if (isOperand(exprsn[j]))
			Stack.push(exprsn[j] - '0');

		else {

			// Operator encountered
			// Pop two elements from Stack
			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			// Use switch case to operate on o1
			// and o2 and perform o1 Or o2.
			switch (exprsn[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}

// Driver code
int main()
{
	string exprsn = "+9*26";
	cout << evaluatePrefix(exprsn) << endl;
	return 0;
}

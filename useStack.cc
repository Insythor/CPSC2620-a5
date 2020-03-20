#include "useStack.h"

bool useStack::isBallanced(const std::string& toCheck)
{
	int brackets = 0;
	for (auto c : toCheck)
		if (c == '(')
			brackets++;
		else if (c == ')')
			brackets--;
	
	return (brackets == 0);
}

bool useStack::evalRPM(const std::string& toRead, int& res)
{
	std::stack<int> myStack;
	// Parse the users input
	std::stringstream ss(toRead);
	std::string temp;
	// Dummy variables for doing operations
	int a, b;

	while (getline(ss, temp, ' '))
	{
	//	std::cout << temp << std::endl;
		if (isdigit(temp[0]))
		{
			myStack.push(std::stoi(temp));
			//std::cout << temp << std::endl;
		}
		else
		{
			switch (temp[0])
			{
			case '+':
				if (!myStack.empty())
				{
					a = myStack.top();
					myStack.pop();
				}
				else
					return false;
				if (!myStack.empty())
				{
					b = myStack.top();
					myStack.pop();
				}
				else
					return false;

				myStack.push(a + b);
				break;

			case '-':
				if (!myStack.empty())
				{
					a = myStack.top();
					myStack.pop();
				}
				else
					return false;
				if (!myStack.empty())
				{
					b = myStack.top();
					myStack.pop();
				}
				else
					return false;
				myStack.push(b - a);
				break;

			case '*':
				if (!myStack.empty())
				{
					a = myStack.top();
					myStack.pop();
				}
				else
					return false;
				if (!myStack.empty())
				{
					b = myStack.top();
					myStack.pop();
				}
				else
					return false;

				myStack.push(a * b);
				break;
			}
		}
	}
	// If the last item in the stack was the result, the equation worked
	if (!myStack.empty())
	{
		res = myStack.top();
		myStack.pop();

		if(myStack.empty())
			return true;
	}
	return 0;
}



#include "CStack.h"
#include "useStack.h"

#include <iostream>
#include <cstdlib>


int main()
{// 2 1 2 + 3 4 + * -
	//std::string tempEquation = "2 1 2 + 3 4 + * -";

	useStack myStack;
	int result;
	bool play = true;

	while (play) 
	{
		std::string input;
		switch (rand() % 2)
		{
		case 0:
			// bracket checker
			std::cout << "Input balanced parentheses: ";
			while (input.empty() || input[0] == '\n')
				getline(std::cin, input);

			if (myStack.isBallanced(input))
				std::cout << "\nGood Job! The parentheses were balanced!!!" << std::endl;
			else
				std::cout << "\nThat was an unbalanced quantity of parentheses\n" << std::endl;
			break;
		case 1:
			// RPN
			std::cout << "Input a RPN Expression: ";
			while (input.empty() || input[0] == '\n')
				getline(std::cin, input);

			if (myStack.evalRPM(input, result))
				std::cout << result << std::endl;
			else
				std::cout << "\nInvalid RPN expression\n" << std::endl;
			break;

		default:
			std::cout << "\nRand Switch Failed\n" << std::endl;
			break;
		}
	}
	return 0;
}
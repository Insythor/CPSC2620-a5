#ifndef USESTACK_H
#define USESTACK_H


#include <iostream>

#include <stack>
#include <string>
#include <sstream>

class useStack
{
public:
	/**
		@brief Checks if the input string has balanced parentheses
		@param[in] std::string& toCheck
		@param[out] bool isBalanced
	*/
	static bool isBallanced(const std::string& toCheck);
	/**
		@brief Performes the given RPN expression
		@param[in] std::string& toEvaluate
		@param[in] int& result of equation
		@param[out] bool isValid equation
	*/
	static bool evalRPM(const std::string& toRead, int& res);
};

#endif // ! USESTACK_H
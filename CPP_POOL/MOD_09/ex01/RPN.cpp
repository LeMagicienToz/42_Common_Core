/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:50:17 by muteza            #+#    #+#             */
/*   Updated: 2024/08/20 11:11:57 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) { }

RPN::RPN( RPN const &src ) { *this = src; }

RPN::~RPN() { }

RPN::RPN( std::stringstream &rpn) 
{

	std::string token;
	while (rpn >> token) 
	{
		if (token == "+" || token == "-" || token == "*" || token == "/") 
		{
			if (stack.size() < 2) 
				throw std::invalid_argument("\033[1;31m[Error]\033[0m insufficient values in the expression.");

			int operator2 = stack.top(); stack.pop();
			int operator1 = stack.top(); stack.pop();
			int result;

			if (token == "+") {
				result = operator1 + operator2;
			} else if (token == "-") {
				result = operator1 - operator2;
			} else if (token == "*") {
				result = operator1 * operator2;
			} else if (token == "/") {
				if (operator2 == 0) {
					throw std::invalid_argument("\033[1;31m[Error]\033[0m division by zero.");
				}
				result = operator1 / operator2;
			}

			stack.push(result);
		}
		else {
			int number;
			std::istringstream iss(token);
			if (!(iss >> number) || number < 0 || number >= 10) {
				throw std::invalid_argument("\033[1;31m[Error]\033[0m invalid argument.");
			}
			stack.push(number);
		}
	}

	if (stack.size() != 1) {
		throw std::invalid_argument("\033[1;31m[Error]\033[0m too many values left in the stack.");
	}
}

void RPN::calculate() {
	int result = stack.top();
	std::cout << "Result: " << result << std::endl;
}


RPN	&RPN::operator=( RPN const &rhs ) {

	(void) rhs;

	std::cout << "Nothing to assign." << std::endl;
	return (*this);
}

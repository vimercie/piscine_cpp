/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:46:40 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/15 18:19:16 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string& str)
{
	operators = "+-*/";

	operations[0] = &RPN::add;
	operations[1] = &RPN::substract;
	operations[2] = &RPN::multiply;
	operations[3] = &RPN::divide;

	parseRPN(str);
}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& src)
{
	if (this != &src)
		this->stack = src.stack;
	return *this;
}

void	RPN::parseRPN(const std::string& str)
{
	size_t	digitCount = 0;

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
		if (!ft_isspace(*it) && !isdigit(*it) && !isOperator(*it))
			throw std::invalid_argument("Invalid expression");

		if (ft_isspace(*it) + ft_isspace(*(it + 1)) != 1
			&& (it + 1) != str.end())
			throw std::invalid_argument("Invalid expression");

		if (isdigit(*it))
		{
			stack.push(*it - '0');
			digitCount++;
		}

		if (isOperator(*it))
		{
			if (digitCount < 2)
				throw std::invalid_argument("Invalid expression");
			calculate(*it);
			digitCount--;
		}
	}
	if (digitCount != 1)
		throw std::invalid_argument("Invalid expression");
}

void	RPN::calculate(char op)
{
	double	num1;
	double	num2;
	size_t 	pos;

	num2 = stack.top();
	stack.pop();
	num1 = stack.top();
	stack.pop();
	pos = operators.find(op);
	if (pos == std::string::npos)
		throw std::invalid_argument("Invalid expression");
	stack.push((this->*operations[operators.find(op)])(num1, num2));
}

double	RPN::add(double num1, double num2)
{
	return num1 + num2;
}

double RPN::substract(double num1, double num2)
{
	return num1 - num2;
}

double RPN::multiply(double num1, double num2)
{
	return num1 * num2;
}

double RPN::divide(double num1, double num2)
{
	if (num2 == 0)
		throw std::invalid_argument("Division by zero");
	return num1 / num2;
}

double	RPN::top() const
{
	return stack.top();
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool	RPN::ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f');
}

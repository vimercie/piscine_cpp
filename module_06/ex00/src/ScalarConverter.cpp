/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:31 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/09 04:00:27 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	if (this != &src)
		*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return *this;
}

void	ScalarConverter::convert(const std::string& str)
{
	try
	{
			std::string	type = getType(str);

		if (type == "char")
			displayConvert(static_cast<char>(str[0]));
		else if (type == "int")
			displayConvert(std::atoi(str.c_str()));
		else if (type == "float" || type == "double")
			displayConvert(std::strtold(str.c_str(), NULL));
		else if (!convertSpecial(str))
			std::cout << "impossible" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

template<typename T>
void	ScalarConverter::displayConvert(T var)
{
	std::string	type = typeid(var).name();

	if (errno == ERANGE)
	{
		std::cout << "Overflow or underflow" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (type == "c")
		std::cout << "'" << var << "'" << std::endl;
	else
		std::cout << toChar(var) << std::endl;

	std::cout << "int: ";
	if (type == "i")
	{
		std::cout << var << std::endl;
	}
	else
		std::cout << toInt(var) << std::endl;

	std::cout << "float: ";
	if (type == "f")
		std::cout << std::fixed << std::setprecision(2) << var << "f" << std::endl;
	else
		std::cout << toFloat(var) << std::endl;

	std::cout << "double: ";
	if (type == "d")
		std::cout << std::fixed << std::setprecision(2) << var << std::endl;
	else
		std::cout << toDouble(var) << std::endl;
}

std::string	ScalarConverter::getType(const std::string& str)
{
	bool	isFloat = false;
	bool	isDouble = false;

	if (str.length() == 1 && !isdigit(str[0]))
		return "char";

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-')
			return "error";
		if (str[i] == '-' && i != 0)
			return "error";
		if (str[i] == '.')
		{
			if (isDouble)
				return "error";
			isDouble = true;
		}
		if (str[i] == 'f')
		{
			if (i != str.length() - 1)
				return "error";
			isFloat = true;
		}
	}

	if (!isFloat && !isDouble && isInLimits(str, "int"))
		return "int";
	else if (isFloat && isInLimits(str, "float"))
		return "float";
	else if (((isDouble || !isInLimits(str, "int")) && isInLimits(str, "double")))
		return "double";
	else
		return "error";
}

template<typename T>
std::string	ScalarConverter::toChar(T var)
{
	std::stringstream	ss;
	int	i = static_cast<int>(var);

	if (i < 33 || i > 126)
		ss << "Non displayable";
	else
		ss << "'" << static_cast<char>(var) << "'";
	return ss.str();
}

template<typename T>
std::string	ScalarConverter::toInt(T var)
{
	std::stringstream	ss;

	if (var < std::numeric_limits<int>::min() || var > std::numeric_limits<int>::max()
		|| var != var)
		ss << "impossible";
	else
		ss << static_cast<int>(var);
	return ss.str();
}

template<typename T>
std::string	ScalarConverter::toFloat(T var)
{
	std::stringstream	ss;

	ss << std::fixed << std::setprecision(2) << var << "f";				// static_cast<float>(var) --> perte de précision
	return ss.str();
}

template<typename T>
std::string	ScalarConverter::toDouble(T var)
{
	std::stringstream	ss;

	ss << std::fixed << std::setprecision(2) << static_cast<double>(var);
	return ss.str();
}

bool	ScalarConverter::convertSpecial(const std::string& str)
{
	if (str == "+inf")
		displayConvert(static_cast<double>(1.0 / 0.0)); // Double Positive Infinity
	else if (str == "-inf")
		displayConvert(static_cast<double>(-1.0 / 0.0)); // Double Negative Infinity
	else if (str == "nan")
		displayConvert(static_cast<double>(0.0 / 0.0)); // Double NaN
	else if (str == "+inff")
		displayConvert(static_cast<float>(1.0f / 0.0f)); // Float Positive Infinity
	else if (str == "-inff")
		displayConvert(static_cast<float>(-1.0f / 0.0f)); // Float Negative Infinity
	else if (str == "nanf")
		displayConvert(static_cast<float>(0.0f / 0.0f)); // Float NaN
	else
		return false;
	return true;
}

bool	ScalarConverter::isInLimits(const std::string& number, const std::string& type)
{
	std::stringstream	limit;

	if (number[0] == '-')
		limit << '-';
	if (type == "int")
		limit << std::numeric_limits<int>::max();
	else if (type == "float" || type == "double")
		limit << LIMIT;

	if ((number.length() == limit.str().length() && number.compare(limit.str()) > 0)
		|| number.length() > limit.str().length())
		return false;
	return true;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:31 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/24 23:39:50 by vimercie         ###   ########lyon.fr   */
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
	std::string	type = getType(str);

	if (type == "char")
		convertChar(static_cast<char>(str[0]));
	else if (type == "int")
		convertInt(std::atoi(str.c_str()));
	else if (type == "float")
		convertFloat(static_cast<float>(std::atof(str.c_str())));
	else if (type == "double")
		convertDouble(static_cast<double>(std::strtod(str.c_str(), NULL)));
	else if (!convertSpecial(str))
		std::cout << "impossible" << std::endl;
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
	else if (isFloat || (!isInLimits(str, "int") && isInLimits(str, "float")))
		return "float";
	else if ((isDouble || (!isInLimits(str, "float") && isInLimits(str, "double"))) && isInLimits(str, "double"))
		return "double";
	else
		return "error";
}

void	ScalarConverter::convertChar(const char& c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::convertInt(const int& i)
{
	std::cout << "char: ";
	if (i < 0 || i > 127)		// f != f is to check if f is NaN
		std::cout << "impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;

	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::convertFloat(const float& f)
{
	std::cout << "char: ";
	if (f < 0 || f > 127 || f != f)
		std::cout << "impossible" << std::endl;
	else if (f < 32 || f == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

	std::cout << "int: ";
	if (f <= std::numeric_limits<int>::min()
		|| f >= std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f << ".0f" << std::endl;

	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::convertDouble(const double& d)
{
	std::cout << "char: ";
	if (d < 0 || d > 127 || d != d)
		std::cout << "impossible" << std::endl;
	else if (d < 32 || d == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d != d)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;;

	std::cout << "double: " << d << std::endl;
}

bool	ScalarConverter::convertSpecial(const std::string& str)
{
	if (str == "+inf")
		convertDouble(1.0 / 0.0); // Double Positive Infinity
	else if (str == "-inf")
		convertDouble(-1.0 / 0.0); // Double Negative Infinity
	else if (str == "nan")
		convertDouble(0.0 / 0.0); // Double NaN
	else if (str == "+inff")
		convertFloat(1.0f / 0.0f); // Float Positive Infinity
	else if (str == "-inff")
		convertFloat(-1.0f / 0.0f); // Float Negative Infinity
	else if (str == "nanf")
		convertFloat(0.0f / 0.0f); // Float NaN
	else
		return false;
	return true;
}

bool	ScalarConverter::isInLimits(const std::string& number, const std::string& type)
{
	std::stringstream	min;
	std::stringstream	max;

	if (type == "int")
	{
		min << std::numeric_limits<int>::min();
		max << std::numeric_limits<int>::max();
	}
	else if (type == "float")
	{
		min << std::numeric_limits<float>::min();
		max << std::numeric_limits<float>::max();
	}
	else if (type == "double")
	{
		min << std::numeric_limits<double>::min();
		max << std::numeric_limits<double>::max();
	}

	if (number[0] == '-')
	{
		if (number.length() >= min.str().length() && number > min.str())
			return false;
	}
	else
	{
		if (number.length() >= max.str().length() && number > max.str())
			return false;
	}
	return true;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:31 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/14 14:48:15 by vimercie         ###   ########lyon.fr   */
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
	if (getType(str) == 'c')
		convertChar(static_cast<char>(str[0]));
	else if (getType(str) == 'i')
		convertInt(static_cast<int>(std::atoi(str.c_str())));
	else if (getType(str) == 'f')
		convertFloat(static_cast<float>(std::atof(str.c_str())));
	else if (getType(str) == 'd')
		convertDouble(static_cast<double>(std::strtod(str.c_str(), NULL)));
	else if (!convertSpecial(str))
		std::cout << "impossible" << std::endl;
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
	if (f < INT_MIN || f > INT_MAX || f != f)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f << "f" << std::endl;

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
	if (d < INT_MIN || d > INT_MAX || d != d)
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

char	ScalarConverter::getType(const std::string& str)
{
	bool	isFloat = false;
	bool	isDouble = false;

	if (str.length() == 1 && !isdigit(str[0]))
		return 'c';

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (isDouble)
				return 0;
			isDouble = true;
		}

		if (str[i] == 'f')
		{
			if (isFloat || str[i + 1])
				return 0;
			isFloat = true;
		}

		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return 0;
	}

	if (isFloat && isDouble)
		return 'f';
	else if (!isFloat && isDouble)
		return 'd';
	else if (!isFloat && !isDouble)
		return 'i';
	else
		return 0;
}

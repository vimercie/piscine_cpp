/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:34 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/11 02:52:36 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define CHAR_MIN -128
# define CHAR_MAX 127
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <string>
# include <iostream>
# include <cstdlib>
# include <cmath>

class	ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& src);

		static void	convert(const std::string& str);
		static void	convertChar(const char& c);
		static void	convertInt(const int& i);
		static void	convertFloat(const float& f);
		static void	convertDouble(const double& d);
		static bool	convertSpecial(const std::string& str);
		static char	getType(const std::string& str);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:34 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/09 03:43:25 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define CHAR_MIN	-128
# define CHAR_MAX	127
# define LIMIT		999999999999999

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <cmath>
# include <cerrno>
# include <limits>
# include <typeinfo>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& src);

		template<typename T>
		static void			displayConvert(T var);
		template<typename T>
		static std::string	toChar(T var);
		template<typename T>
		static std::string	toInt(T var);
		template<typename T>
		static std::string	toFloat(T var);
		template<typename T>
		static std::string	toDouble(T var);

		static std::string	getType(const std::string& str);
		static bool			convertSpecial(const std::string& str);
		static bool			isInLimits(const std::string& number, const std::string& type);
	public:
		static void			convert(const std::string& str);
};

#endif
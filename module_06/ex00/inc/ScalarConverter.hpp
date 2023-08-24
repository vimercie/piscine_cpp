/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:34 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/24 18:18:17 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define CHAR_MIN -128
# define CHAR_MAX 127

# include <string>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cmath>
# include <limits>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& src);

		static std::string	getType(const std::string& str);
		static void			convertChar(const char& c);
		static void			convertInt(const int& i);
		static void			convertFloat(const float& f);
		static void			convertDouble(const double& d);
		static bool			convertSpecial(const std::string& str);
		static bool			isInLimits(const std::string& number, const std::string& type);
	public:
		static void	convert(const std::string& str);
};

#endif
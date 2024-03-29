/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:04:58 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/21 17:43:47 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class	Fixed
{
	private:
		int					fixedPointValue;
		static const int	bitsInFraction;
	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();

		Fixed&	operator=(const Fixed& src);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		int		toInt() const;
		float	toFloat() const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& n);

#endif
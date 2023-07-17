/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:04:58 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/17 21:04:59 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					fixedPointValue;
		static const int	bitsInFraction = 8;
	public:
		Fixed() : fixedPointValue(0) {};
		Fixed(const Fixed& src) : fixedPointValue(src.fixedPointValue) {};
		Fixed&	operator=(const Fixed& src);
		
};

#endif
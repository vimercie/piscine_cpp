/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:04:58 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/19 18:14:51 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					fixedPointValue;
		static const int	bitsInFraction;
	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed(const int n);
		Fixed&	operator=(const Fixed& src);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
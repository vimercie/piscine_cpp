/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:06:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/20 18:30:02 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::bitsInFraction = 8;

Fixed::Fixed() : fixedPointValue(0) {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed& src) : fixedPointValue(src.fixedPointValue) {std::cout << "Copy constructor called" << std::endl;}

Fixed::Fixed(const int n) : fixedPointValue(n << this->bitsInFraction) {}

Fixed::Fixed(const float n) : fixedPointValue(roundf(n * (1 << this->bitsInFraction))) {}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

Fixed&	Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		setRawBits(src.getRawBits());
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed n)
{
	os << n.toFloat();
	return (os);
}

int	Fixed::getRawBits() const
{
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

int	Fixed::toInt() const
{
	return (this->getRawBits() >> this->bitsInFraction);
}

float	Fixed::toFloat() const
{
	std::cout << "test" << std::endl;
	return (0);
}

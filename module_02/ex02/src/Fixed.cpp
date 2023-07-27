/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:06:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/27 22:15:03 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::bitsInFraction = 8;

// Constructeurs
Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const Fixed& src) : fixedPointValue(src.fixedPointValue) {}

Fixed::Fixed(const int n) : fixedPointValue(n << this->bitsInFraction) {}

Fixed::Fixed(const float n) : fixedPointValue(roundf(n * (1 << this->bitsInFraction))) {}

// Destructeur
Fixed::~Fixed() {}

// Surcharge de l'opérateur d'assignation
Fixed&	Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		setRawBits(src.getRawBits());
	return (*this);
}

// Surcharge des opérateurs de comparaison (à faire)
bool	Fixed::operator<(const Fixed& src) const {return (this->getRawBits() < src.getRawBits());}

bool	Fixed::operator>(const Fixed& src) const {return (this->getRawBits() > src.getRawBits());}

bool	Fixed::operator<=(const Fixed& src) const {return (this->getRawBits() <= src.getRawBits());}

bool	Fixed::operator>=(const Fixed& src) const {return (this->getRawBits() >= src.getRawBits());}

bool	Fixed::operator==(const Fixed& src) const {return (this->getRawBits() == src.getRawBits());}

bool	Fixed::operator!=(const Fixed& src) const {return (this->getRawBits() != src.getRawBits());}

// Surcharge des opérateurs d'incrémentation
Fixed&	Fixed::operator++()
{
	++this->fixedPointValue;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--this->fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++this->fixedPointValue;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--this->fixedPointValue;
	return (temp);
}

// Surcharges des opérateurs arithmétiques
Fixed	Fixed::operator+(const Fixed& src) const
{return (Fixed(this->toFloat() + src.toFloat()));}

Fixed	Fixed::operator-(const Fixed& src) const
{return (Fixed(this->toFloat() - src.toFloat()));}

Fixed	Fixed::operator*(const Fixed& src) const
{return (Fixed(this->toFloat() * src.toFloat()));}

Fixed	Fixed::operator/(const Fixed& src) const
{return (Fixed(this->toFloat() / src.toFloat()));}

// Surcharge de l'opérateur d'affichage
std::ostream&	operator<<(std::ostream& os, const Fixed& n)
{
	os << n.toFloat();
	return (os);
}

// Fonctions membres
int	Fixed::getRawBits() const {return (this->fixedPointValue);}

void	Fixed::setRawBits(int const raw) {this->fixedPointValue = raw;}

int	Fixed::toInt() const {return (this->getRawBits() >> this->bitsInFraction);}

float	Fixed::toFloat() const {return ((float)this->getRawBits() / (1 << this->bitsInFraction));}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

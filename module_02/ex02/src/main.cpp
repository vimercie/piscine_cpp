/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:06:03 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/27 22:15:31 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// int main()
// {
// 	Fixed		a;
// 	Fixed const	b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max(a, b) << std::endl;

// 	return 0;
// }

int	main()
{
	Fixed	a(Fixed(10.05f) * Fixed(2));
	Fixed	b = 2;
	Fixed	c(-10.5f);

	std::cout << "int(a)\t\t= " << a.toInt() << std::endl;
	std::cout << "int(b)\t\t= " << b.toInt() << std::endl;
	std::cout << "int(c)\t\t= " << c.toInt() << std::endl;
	std::cout << std::endl;
	std::cout << "float(a)\t= " << a.toFloat() << std::endl;	// <- la
	std::cout << "float(b)\t= " << b << std::endl;				// <- même
	std::cout << "float(c)\t= " << c << std::endl;				// <- chose
	std::cout << std::endl;
	std::cout << "fixed(a)\t= " << a.getRawBits() << std::endl;
	std::cout << "fixed(b)\t= " << b.getRawBits() << std::endl;
	std::cout << "fixed(c)\t= " << c.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << "a < b\t= " << (a < b) << std::endl;
	std::cout << "a > b\t= " << (a > b) << std::endl;
	std::cout << "a <= b\t= " << (a <= b) << std::endl;
	std::cout << "a >= b\t= " << (a >= b) << std::endl;
	std::cout << "a == b\t= " << (a == b) << std::endl;
	std::cout << "a != b\t= " << (a != b) << std::endl;
	std::cout << std::endl;
	std::cout << "float(a) + float(b) = " << a.toFloat() + b.toFloat() << std::endl;
	std::cout << "float(a) - float(b) = " << a.toFloat() - b.toFloat() << std::endl;
	std::cout << "float(a) * float(b) = " << a.toFloat() * b.toFloat() << std::endl;
	std::cout << "float(a) / float(b) = " << a.toFloat() / b.toFloat() << std::endl;
	std::cout << std::endl;
	std::cout << "float(b)\t= " << b << std::endl;
	std::cout << "fixed(b)\t= " << b.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << "++b\t\t= " << ++b << std::endl;
	std::cout << std::endl;
	std::cout << "float(b)\t= " << b << std::endl;
	std::cout << "fixed(b)\t= " << b.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << "b--\t\t= " << b-- << std::endl;
	std::cout << std::endl;
	std::cout << "float(b)\t= " << b << std::endl;
	std::cout << "fixed(b)\t= " << b.getRawBits() << std::endl;
	std::cout << std::endl;
	std::cout << "min(a, b)\t= " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b)\t= " << Fixed::max((const Fixed)a, (const Fixed)b) << std::endl;
}

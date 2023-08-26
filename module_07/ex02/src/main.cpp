/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:44:50 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/16 04:26:31 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include "../inc/Array.tpp"

int	main()
{
	Array<int> a(5);
	Array<int> b(a);
	Array<int> c;

	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = i;
		b[i] = i + 1;
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
		std::cout << std::endl;
	}

	c = a;

	try
	{
		std::cout << "a[3] = " << a[3] << std::endl;
		std::cout << "a[-1] = " << a[-1] << std::endl;
		std::cout << "b[5] = " << b[5] << std::endl;
		std::cout << "c[4] = " << c[4] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<std::string> s(3);

	s[0] = "Hello";
	s[1] = "World";
	s[2] = "!";
	
	for (size_t i = 0; i < s.size(); i++)
		std::cout << "s[" << i << "] = " << s[i] << std::endl;
	
	std::cout << std::endl;

	return (0);
}

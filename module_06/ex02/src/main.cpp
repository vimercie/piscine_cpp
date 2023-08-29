/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:00:04 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/29 17:16:46 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate()
{
	srand((unsigned int )time(NULL));
	int	random = rand() % 3;

	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
}

int	main()
{
	Base	*A = new class A;
	Base	*B = new class B;
	Base	*C = new class C;
	Base	*random = generate();
	Base	*null = NULL;

	identify(*A);
	identify(*B);
	identify(*C);

	std::cout << std::endl;

	identify(A);
	identify(B);
	identify(C);

	std::cout << std::endl;

	identify(random);
	identify(*random);

	std::cout << std::endl;

	identify(null);
	identify(*null);

	delete A;
	delete B;
	delete C;
	delete random;

	return (0);
}

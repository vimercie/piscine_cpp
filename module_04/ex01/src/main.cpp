/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:24:38 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:40:13 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int	main()
{
	int			i;
	const int	size = 6;
	Animal		*animals[10];

	for (i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	for (i = 0; i < size; i++)
		animals[i]->makeSound();
	
	for (i = 0; i < size; i++)
	{
		std::cout << std::endl;
		delete animals[i];
	}

	std::cout << std::endl;
	std::cout << std::endl;

	Cat	basic;
	Cat	tmp1(basic);
	Cat	tmp2 = basic;

	Dog	basic2;
	Dog	tmp3(basic2);
	Dog	tmp4 = basic2;

	std::cout << std::endl;

	return (0);
}

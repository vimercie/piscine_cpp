/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:24:38 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 18:15:50 by vimercie         ###   ########lyon.fr   */
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
	// Animal		animal;			--> Ne compilera pas

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
	return (0);
}

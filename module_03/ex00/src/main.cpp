/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/29 14:23:11 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int	main()
{
	ClapTrap	bob("Bob");

	std::cout << std::endl;

	bob.takeDamage(4);
	bob.beRepaired(1);

	std::cout << std::endl;

	ClapTrap	jose("Jose");

	std::cout << std::endl;

	bob.takeDamage(7);

	std::cout << std::endl;

	bob = jose;

	std::cout << std::endl;

	bob.takeDamage(70);
	jose.takeDamage(7);
	jose.beRepaired(3);

	std::cout << std::endl;

	for (int i = 0; i < 12; i++)
		jose.attack("jose");
	
	std::cout << std::endl;

	jose.takeDamage(4);

	std::cout << std::endl;
	return (0);
}
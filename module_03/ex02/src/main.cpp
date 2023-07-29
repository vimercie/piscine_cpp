/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/29 15:05:45 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main()
{
	FragTrap	bro("Bro");

	std::cout << std::endl;

	bro.attack("Steve");
	bro.beRepaired(20);
	bro.highFivesGuys();
	bro.takeDamage(100);
	bro.takeDamage(100);

	std::cout << std::endl;

	bro.attack("Steve");
	bro.beRepaired(20);
	bro.highFivesGuys();
	bro.takeDamage(100);
	bro.takeDamage(100);

	std::cout << std::endl;

	return (0);
}
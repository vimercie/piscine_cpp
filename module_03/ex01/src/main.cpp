/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/29 14:54:37 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main()
{
	ScavTrap	bro("Bro");

	std::cout << std::endl;

	bro.attack("Steve");
	bro.beRepaired(20);
	bro.guardGate();
	bro.takeDamage(100);
	bro.takeDamage(100);

	std::cout << std::endl;

	bro.attack("Steve");
	bro.beRepaired(20);
	bro.guardGate();
	bro.takeDamage(100);
	bro.takeDamage(100);

	std::cout << std::endl;

	return (0);
}
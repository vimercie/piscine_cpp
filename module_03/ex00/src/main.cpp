/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/29 14:12:22 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int	main()
{
	ClapTrap	bob("Bob");

	bob.takeDamage(4);
	bob.beRepaired(1);

	ClapTrap	jose(bob);
	bob.takeDamage(7);
	bob = jose;
	bob.takeDamage(7);
	jose.takeDamage(5);
	jose.beRepaired(3);
	for (int i = 0; i < 12; i++)
		jose.attack("jose");
	jose.takeDamage(4);
	return (0);
}
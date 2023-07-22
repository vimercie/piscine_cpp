/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/22 02:50:52 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int	main()
{
	ClapTrap	bob("Bob");

	bob.attack("Jose");
	bob.takeDamage(4);
	bob.beRepaired(1);

	ClapTrap	jose(bob);
	jose.takeDamage(6);
	jose.beRepaired(3);
	jose.takeDamage(4);
	return (0);
}
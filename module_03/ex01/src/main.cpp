/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/24 15:34:17 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main()
{
	ScavTrap	mauricio("Mauricio");

	mauricio.guardGate();
	mauricio.attack("bob");
	mauricio.takeDamage(57);
	mauricio.beRepaired(40);


	ScavTrap	t_mac(mauricio);
	t_mac.attack("oorihgdjd");
	return (0);
}
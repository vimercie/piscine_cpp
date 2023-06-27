/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:51:40 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/26 13:34:38 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie	Zomb1 = Zombie("Le Z");
	Zombie	*Zomb2 = newZombie("Zaza");

	Zomb1.announce();
	Zomb2->announce();
	randomChump("Le Zin");
	delete(Zomb2);
}

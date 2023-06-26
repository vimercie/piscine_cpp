/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:47:07 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/26 15:05:24 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	int	size;

	size = 10;
	Zombie	*Zombies = zombieHorde(size, "Le Z");
	for (int i = 0; i < size; i++)
		Zombies[i].announce();
	delete[] Zombies;
}
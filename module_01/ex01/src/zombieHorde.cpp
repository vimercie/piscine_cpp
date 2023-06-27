/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:49:52 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/26 14:46:08 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*res = new Zombie[N];
	for (int i = 0; i < N; i++)
		res[i].set_name(name);
	return (res);
}

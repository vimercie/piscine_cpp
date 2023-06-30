/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:02:37 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/30 19:43:36 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}

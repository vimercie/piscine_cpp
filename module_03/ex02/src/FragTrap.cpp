/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:57:27 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/29 15:08:29 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "(FragTrap) default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "(FragTrap) name constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{std::cout << "(FragTrap) copy constructor called" << std::endl;}

FragTrap::~FragTrap() {std::cout << "(FragTrap) destructor called" << std::endl;}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	std::cout << "(FragTrap) " << this->name << " assignment operator called." << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (this->hit_points <= 0)
		std::cout << "(FragTrap) " << this->name << " can't ask for high fives, he's dead." << std::endl;
	else
		std::cout << "(FragTrap) " << this->name << " is asking for high fives." << std::endl;
}


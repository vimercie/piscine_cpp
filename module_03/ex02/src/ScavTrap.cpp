/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:39:02 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/29 14:59:38 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "(ScavTrap) default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "(ScavTrap) name constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{std::cout << "(ScavTrap) copy constructor called" << std::endl;}

ScavTrap::~ScavTrap() {std::cout << "(ScavTrap) destructor called" << std::endl;}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "(ScavTrap) " << this->name << " assignment operator called." << std::endl;
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points <= 0 || this->energy_points <= 0)
	{
		if (this->hit_points <= 0)
			std::cout << "(ScavTrap) " << this->name << " is dead";
		else
			std::cout << "(ScavTrap) " << this->name << " has run out of energy points";
		std::cout << ", he can't attack." << std::endl;
		return ;
	}
	this->energy_points -= 1;
	std::cout << "(ScavTrap) " << this->name << " attacks " << target
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->hit_points <= 0)
		std::cout << "(ScavTrap) " << this->name << " is dead, he can't enter Gate keeper mode." << std::endl;
	else
		std::cout << "(ScavTrap) " << this->name << " Gate keeper mode activated" << std::endl;
}

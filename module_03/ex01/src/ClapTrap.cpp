/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:54 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/24 15:31:29 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("no_name"), hit_points(10), energy_points(10), attack_damage(0)
{std::cout << "ClapTrap default constructor called" << std::endl;}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{std::cout << "ClapTrap name constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& src) : name(src.name), hit_points(src.hit_points), energy_points(src.energy_points), attack_damage(src.attack_damage)
{std::cout << "ClapTrap copy constructor called" << std::endl;}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap destructor called" << std::endl;}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	this->name = src.name;
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left" << std::endl;
		return ;
	}
	this->energy_points -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has already no hit points left" << std::endl;
		return ;
	}
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount
		<< " points of damage!" << std::endl;
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " dies" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	this->energy_points -= 1;
	std::cout << "ClapTrap " << this->name << " heals " << amount
		<< " hit points!" << std::endl;
}

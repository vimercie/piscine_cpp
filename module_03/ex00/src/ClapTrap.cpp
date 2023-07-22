/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:46:54 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/22 02:49:46 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("no_name"), hit_points(10), energy_points(10), attack_damage(0)
{std::cout << "Default constructor called" << std::endl;}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{std::cout << "Name constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& src) : name(src.name), hit_points(src.hit_points), energy_points(src.energy_points), attack_damage(src.attack_damage)
{std::cout << "Copy constructor called" << std::endl;}

ClapTrap::~ClapTrap() {std::cout << "Destructor called" << std::endl;}

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
	this->energy_points -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attack_damage << " points of damage!" << std::endl;
	if (this->energy_points <= 0)
		this->~ClapTrap();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount
		<< " points of damage!" << std::endl;
	if (this->hit_points <= 0)
		this->~ClapTrap();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->energy_points -= 1;
	std::cout << "ClapTrap " << this->name << " heals " << amount
		<< " hit points!" << std::endl;
	if (this->energy_points <= 0)
		this->~ClapTrap();
}

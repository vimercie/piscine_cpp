/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:38:44 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:51:37 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type.assign("Dog");
}

Cat::Cat(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {std::cout << "Dog destructor called" << std::endl;}

Dog&	Dog::operator=(const Dog& src)
{
	this->type = src.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}

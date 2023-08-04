/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:38:44 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:53:55 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type.assign("Dog");
	this->brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& src)
{
	if (this == &src)
		return (*this);

	this->type.assign(src.type);
	*this->brain = *src.brain;

	std::cout << "Dog copy assignment called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "WOOF WOOF" << std::endl;
}

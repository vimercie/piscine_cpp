/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:39:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:54:43 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type.assign("Cat");
	this->brain = new Brain;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*src.brain);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& src)
{
	if (this == &src)
		return (*this);

	delete brain;

	this->type = src.type;
	this->brain = new Brain(*src.brain);
	
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MIAOU MIAOU" << std::endl;
}

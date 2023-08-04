/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:39:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:04:50 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type.assign("Cat");
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl;}

Cat&	Cat::operator=(const Cat& src)
{
	this->type.assign(src.type);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MIAOU MIAOU" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:24:36 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:02:15 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : type("Unknown") {std::cout << "Animal default constructor called" << std::endl;}

Animal::Animal(const Animal& src) : type(src.type) {std::cout << "Animal copy constructor called" << std::endl;}

Animal::~Animal() {std::cout << "Animal destructor called" << std::endl;}

Animal&	Animal::operator=(const Animal& src)
{
	if (this == &src)
		return (*this);

	this->type.assign(src.type);
	return (*this);
}

const std::string&	Animal::getType() const {return (this->type);}

void	Animal::setType(const std::string src) {this->type.assign(src);}

void	Animal::makeSound() const {std::cout << "UNDEFINED" << std::endl;}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:46:40 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 16:03:33 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongUnknown") {std::cout << "WrongAnimal default constructor called" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {std::cout << "WrongAnimal copy constructor called" << std::endl;}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructor called" << std::endl;}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	this->type.assign(src.type);
	return (*this);
}

const std::string&	WrongAnimal::getType() const {return (this->type);}

void	WrongAnimal::setType(const std::string src) {this->type.assign(src);}

void	WrongAnimal::makeSound() const {std::cout << "WRONG UNDEFINED" << std::endl;}
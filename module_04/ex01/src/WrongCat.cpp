/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:46:27 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 15:50:37 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type.assign("WrongCat");
}

WrongCat::~WrongCat() {std::cout << "WrongCat destructor called" << std::endl;}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	this->type.assign(src.type);
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG MIAOU MIAOU" << std::endl;
}
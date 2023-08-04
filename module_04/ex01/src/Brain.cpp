/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:19:42 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/04 16:28:45 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() : ideas(new std::string[100]) {std::cout << "Brain default constructor called" << std::endl;}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
	delete[] ideas;
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& src)
{
	if (this == &src)
		return *this;
	
	delete[] ideas;

	ideas = new std::string[100];
	for (int i = 0; i < 100; ++i)
		ideas[i] = src.ideas[i];

	return *this;
}

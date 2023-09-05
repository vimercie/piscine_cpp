/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:59:04 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/05 18:24:32 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

#include <stdexcept>

Span::Span() {}

Span::Span(unsigned int size) : size(size) {}

Span::Span(const Span& src)
{
	*this = src;
}

Span::~Span() {}

Span&	Span::operator=(const Span& src)
{
	if (this != &src)
	{
		size = src.size;
		tab.clear();
		tab = src.tab;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (tab.size() >= size)
		throw std::invalid_argument("Span is full");
	tab.insert(n);
}

unsigned int	Span::longestSpan() const
{
	if (tab.size() < 2)
		throw std::invalid_argument("Span is empty or has only one element");
	return *tab.end() - *tab.begin();

}

unsigned int	Span::shortestSpan() const
{
	unsigned int	res = *tab.end() - *tab.begin();

	if (tab.size() < 2)
		throw std::invalid_argument("Span is empty or has only one element");
	
	// TODO
}

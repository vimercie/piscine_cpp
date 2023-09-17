/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:59:04 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/18 01:27:12 by vimercie         ###   ########lyon.fr   */
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
	if (tab.find(n) != tab.end())
		throw std::invalid_argument("Number already exists in Span");
	tab.insert(n);
}

void	Span::addNumbers(int* begin, int* end)
{
	if (std::distance(begin, end) > size)
		throw std::invalid_argument("Span size is too small");

	for (int* it = begin; it != end; it++)
	{
		if (tab.find(*it) != tab.end())
			throw std::invalid_argument("Number already exists in Span");
	}

	tab.insert(begin, end);
}

unsigned int	Span::longestSpan() const
{
	std::set<int>::iterator lastElem = tab.end();

	if (tab.size() < 2)
		throw std::invalid_argument("Span is empty or has only one element");
	lastElem--;
	return *lastElem - *tab.begin();
}

unsigned int	Span::shortestSpan() const
{
	std::set<int>::iterator it = tab.begin();
	std::set<int>::iterator it2 = tab.begin();
	unsigned int 			res = longestSpan();

	if (tab.size() < 2)
		throw std::invalid_argument("Span is empty or has only one element");
	
	it2++;

	while (it2 != tab.end())
	{
		if (res > static_cast<unsigned int>(*it2 - *it))
			res = *it2 - *it;
		it++;
		it2++;
	}
	return res;
}

void	Span::printSet() const
{
	for (std::set<int>::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << std::endl;
}

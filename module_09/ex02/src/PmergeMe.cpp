/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:39:11 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/18 16:08:51 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	(void)src;
	return *this;
}

void	PmergeMe::parsing(char **argv)
{
	(void)argv;
}

bool	PmergeMe::isInLimits(const std::string& str) const
{
	std::stringstream limit;

	limit << INT_MAX;

	if (str.length() > 10)
		return false;
	if (str.length() < 10)
		return true;
	if (str > limit.str())
		return false;
	return true;
}

bool 	PmergeMe::isSorted()
{
	return false;
}

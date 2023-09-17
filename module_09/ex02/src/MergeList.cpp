/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeList.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:13:11 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/17 18:05:18 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MergeList.hpp"

MergeList::MergeList(char **argv)
{
	parsing(argv);
}

MergeList::MergeList(const MergeList& src) : PmergeMe(src)
{
	*this = src;
}

MergeList::~MergeList() {}

MergeList&	MergeList::operator=(const MergeList& src)
{
	if (this != &src)
		list = src.list;
	return *this;
}

void	MergeList::parsing(char **argv)
{
	size_t i = 1;

	while (argv[i])
	{
		size_t j = 0;
		std::string tmp = "";

		while (argv[i][j])
		{				
			if (!isdigit(argv[i][j]))
				throw std::invalid_argument("Invalid argument");
			tmp.push_back(argv[i][j]);
			j++;
		}
		if (isInLimits(tmp))
			list.push_back(std::atoi(tmp.c_str()));
		else
			throw std::invalid_argument("Invalid argument");
		i++;
	}
}

void	MergeList::mergeInsertionSort(listIterator start, listIterator end)
{
	const int seuilInsertion = 10; // Seuil pour basculer vers le tri par insertion

	if (start != end)
	{
		if (std::distance(start, end) < seuilInsertion)
			insertionSort(start, end);
		else
		{
			listIterator middle = findMedian(start, end);

			mergeInsertionSort(start, middle);
			mergeInsertionSort(middle, end);
			std::inplace_merge(start, middle, end);
		}
	}
}

void	MergeList::insertionSort(listIterator start, listIterator end)
{
	for (listIterator it = start; it != end; ++it)
	{
		int current = *it;
		listIterator it2 = it;

		while (it2 != start)
		{
			listIterator prev = it2;
			--prev;

			if (*prev > current)
			{
				*it2 = *prev;
				it2 = prev;
			}
			else
				break;
		}

		*it2 = current;
	}
}

listIterator	MergeList::findMedian(listIterator start, listIterator end)
{
	size_t distance = std::distance(start, end);

	std::advance(start, distance / 2);
	return start;
}

bool	MergeList::isSorted()
{
	if (list.empty() || list.begin() == list.end())
		return true;

	listIterator it = list.begin();
	listIterator next = it;
	++next;

	while (next != list.end())
	{
		if (*it > *next)
			return false;

		++it;
		++next;
	}

	return true;
}


listIterator	MergeList::begin()
{
	return list.begin();
}

listIterator	MergeList::end()
{
	return list.end();
}

void	MergeList::printList()
{
	for (listIterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void	MergeList::printPartialList(size_t n)
{
	size_t size = list.size();

	if (size <= 1 || n >= size)
	{
		for (listIterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << ' ';
	}
	else
	{
		size_t middle = n / 2;
		listIterator it = list.begin();

		for (size_t i = 0; i < middle; ++i)
		{
			std::cout << *it << ' ';
			++it;
		}

		std::cout << "[...] ";

		it = list.end();
		std::advance(it, -static_cast<int>(middle)); // Avance de "middle" positions depuis la fin.
		
		while (it != list.end())
		{
			std::cout << *it << ' ';
			++it;
		}
	}

	std::cout << std::endl;
}
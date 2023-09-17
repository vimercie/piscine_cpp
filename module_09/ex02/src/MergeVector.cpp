/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeVector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:19:28 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/17 18:03:09 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MergeVector.hpp"

MergeVector::MergeVector(char **argv)
{
	parsing(argv);
}

MergeVector::MergeVector(const MergeVector& src) : PmergeMe(src)
{
	*this = src;
}

MergeVector::~MergeVector() {}

MergeVector& MergeVector::operator=(const MergeVector& src)
{
	if (this != &src)
		vector = src.vector;
	return *this;
}

void	MergeVector::parsing(char **argv)
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
			vector.push_back(std::atoi(tmp.c_str()));
		else
			throw std::invalid_argument("Invalid argument");
		i++;
	}
}

void	MergeVector::mergeInsertionSort(vectorIterator start, vectorIterator end)
{
	const int seuilInsertion = 10; // Seuil pour basculer vers le tri par insertion

	if (start != end)
	{
		if (std::distance(start, end) < seuilInsertion)
			insertionSort(start, end);
		else
		{
			vectorIterator middle = findMedian(start, end);

			mergeInsertionSort(start, middle);
			mergeInsertionSort(middle, end);
			std::inplace_merge(start, middle, end);
		}
	}
}

void MergeVector::insertionSort(vectorIterator start, vectorIterator end)
{
	for (vectorIterator it = start + 1; it != end; ++it)
	{
		int				current = *it;
		vectorIterator	it2 = it;

		const int valueToInsert = current;

		while (it2 != start && *(it2 - 1) > valueToInsert)
		{
			std::swap(*it2, *(it2 - 1));
			--it2;
		}

		*it2 = valueToInsert;
	}
}

vectorIterator	MergeVector::findMedian(vectorIterator start, vectorIterator end)
{
	size_t distance = std::distance(start, end);

	std::advance(start, distance / 2);
	return start;
}

bool	MergeVector::isSorted()
{
	for (vectorIterator it = vector.begin(); it != vector.end() - 1; it++)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}

vectorIterator	MergeVector::begin()
{
	return vector.begin();
}

vectorIterator	MergeVector::end()
{
	return vector.end();
}

void	MergeVector::printVector()
{
	for (vectorIterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void MergeVector::printPartialVector(size_t n)
{
	size_t size = vector.size();

	if (size <= 1 || n >= size)
	{
		// Si le vecteur a une taille de 0 ou 1, affiche simplement son contenu.
		for (vectorIterator it = vector.begin(); it != vector.end(); it++)
			std::cout << *it << ' ';
	}
	else
	{
		size_t	middle = n / 2;

		for (size_t i = 0; i < middle; ++i)
			std::cout << vector[i] << ' ';
		
		std::cout << "[...] ";

		for (size_t i = size - middle; i < size; ++i)
			std::cout << vector[i] << ' ';
	}

	std::cout << std::endl;
}

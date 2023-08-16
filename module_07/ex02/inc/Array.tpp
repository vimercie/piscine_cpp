/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:20:08 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/16 04:19:09 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), array_size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), array_size(n)
{
	std::cout << "Parametric constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	array_size = src.size();
	array = new T[src.size()];
	for (size_t i = 0; i < size(); i++)
		array[i] = src.array[i];
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	if (array)
		delete[] array;
	std::cout << "Destructor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		if (array)
			delete[] array;

		array_size = src.size();
		array = new T[src.size()];

		for (size_t i = 0; i < size(); i++)
			array[i] = src.array[i];
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= size())
		throw std::out_of_range("Out of range");
	return array[i];
}

template <typename T>
size_t Array<T>::size() const
{
	return array_size;
}

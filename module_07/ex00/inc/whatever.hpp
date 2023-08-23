/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 02:58:10 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/23 18:35:08 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <typeinfo>

template <typename T>
void swap(T &a, T &b)
{
	if (typeid(a) != typeid(b))
		throw std::invalid_argument("Type mismatch");
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T &a, T &b)
{
	if (typeid(a) != typeid(b))
		throw std::invalid_argument("Type mismatch");
	if (a < b)
		return (a);
	return (const T& b);
}

template <typename T>
T max(T &a, T &b)
{
	if (typeid(a) != typeid(b))
		throw std::invalid_argument("Type mismatch");
	if (a > b)
		return (a);
	return (const T& b);
}

#endif
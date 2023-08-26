/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:06:23 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/16 03:14:32 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *tab, size_t size, void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(tab[i]);
}

template <typename T>
void	print(T const &x)
{
	std::cout << x << std::endl;
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:17:24 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/16 04:05:49 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class	Array
{
	private:
		T		*array;
		size_t	array_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& a);
		~Array();

		Array &operator=(Array const &a);
		T &operator[](size_t i);

		size_t size() const;
};

#endif
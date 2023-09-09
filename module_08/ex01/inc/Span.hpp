/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:19:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/09 15:41:23 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <set>

class Span
{
	private:
		std::set<int>	tab;
		unsigned int	size;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& src);
		~Span();

		Span&	operator=(const Span& src);

		void			addNumber(int n);
		void			addNumbers(int* begin, int* end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			printSet() const;
};

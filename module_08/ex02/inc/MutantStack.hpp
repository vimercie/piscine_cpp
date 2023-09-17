/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:18:47 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/18 01:31:06 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& src);
		~MutantStack();

		MutantStack&	operator=(const MutantStack& src);

		typedef typename std::deque<T>::iterator stackIterator;
		stackIterator begin();
		stackIterator end();
};

# include "MutantStack.tpp"

#endif
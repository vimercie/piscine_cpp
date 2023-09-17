/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:54:54 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/17 18:02:26 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <iterator>
# include <list>
# include <vector>
# include <algorithm>
# include <limits.h>
# include <ctime>

class	PmergeMe
{
	protected:
		PmergeMe();
		PmergeMe(const PmergeMe& src);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& src);

		virtual void	parsing(char **argv) = 0;
		virtual void	mergeInsertionSort();
		virtual void	insertionSort();
		virtual bool	isInLimits(const std::string& str) const;
		virtual bool 	isSorted();
};

#endif
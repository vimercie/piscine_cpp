/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeList.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:20:55 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/17 18:03:24 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGELIST_HPP
# define MERGELIST_HPP

# include "PmergeMe.hpp"

# include <iostream>
# include <string>
# include <list>

typedef std::list<int>::iterator listIterator;

class	MergeList : public PmergeMe
{
	private:
		MergeList();

		virtual void	parsing(char **argv);
		virtual void	insertionSort(listIterator start, listIterator end);

		listIterator	findMedian(listIterator start, listIterator end);

		std::list<int>	list;
	public:
		MergeList(char **argv);
		MergeList(const MergeList& src);
		~MergeList();

		MergeList& operator=(const MergeList& src);

		virtual void	mergeInsertionSort(listIterator begin, listIterator end);
		virtual bool	isSorted();

		listIterator	begin();
		listIterator	end();
		void			printList();
		void			printPartialList(size_t n);
};

#endif
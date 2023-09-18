/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeVector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:19:11 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/18 16:09:57 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEVECTOR_HPP
# define MERGEVECTOR_HPP

# include "PmergeMe.hpp"

# include <iostream>
# include <string>
# include <vector>

typedef std::vector<int>::iterator vectorIterator;

class	MergeVector : public PmergeMe
{
	private:
		MergeVector();

		virtual void	parsing(char **argv);

		void			insertionSort(vectorIterator start, vectorIterator end);
		vectorIterator	findMedian(vectorIterator start, vectorIterator end);

		std::vector<int>	vector;
	public:
		MergeVector(char **argv);
		MergeVector(const MergeVector& src);
		~MergeVector();

		MergeVector& operator=(const MergeVector& src);

		virtual bool	isSorted();

		void			mergeInsertionSort(vectorIterator begin, vectorIterator end);
		void			printVector();
		void			printPartialVector(size_t n);
		vectorIterator	begin();
		vectorIterator	end();
};

#endif
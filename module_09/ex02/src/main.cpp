/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:38:39 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/17 17:51:09 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MergeVector.hpp"
#include "../inc/MergeList.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Usage: ./PmergeMe [positive integer list]" << std::endl;
		return 1;
	}

	try
	{
		MergeVector mv(argv);
		MergeList	ml(argv);

		std::cout << "Before:" << std::endl;

		std::cout << "std::vector<int> :\t";
		mv.printPartialVector(10);
		// mv.printVector();

		std::cout << "std::list<int> :\t";
		ml.printPartialList(10);
		// ml.printList();

		clock_t	vectorStart = clock();
		mv.mergeInsertionSort(mv.begin(), mv.end());
		clock_t vectorEnd = clock();

		clock_t	listStart = clock();
		ml.mergeInsertionSort(ml.begin(), ml.end());
		clock_t listEnd = clock();

		std::cout << std::endl;

		std::cout << "After:" << std::endl;

		std::cout << "std::vector<int> :\t";
		mv.printPartialVector(10);
		// mv.printVector();

		std::cout << "std::list<int> :\t";
		ml.printPartialList(10);
		// ml.printList();

		// std::cout << "is_sorted:\t" << std::boolalpha << mv.isSorted() << std::endl;

		std::cout << std::endl;

		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector<int> : \t"<< std::fixed << (double)(vectorEnd - vectorStart) / CLOCKS_PER_SEC << " s" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::list<int> :   \t"<< std::fixed << (double)(listEnd - listStart) / CLOCKS_PER_SEC << " s" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:37:41 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/09 15:51:21 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
	try
	{
		
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << std::endl;

		sp.printSet();

		std::cout << std::endl;

		Span sp2 = Span(5);
		int myArray[] = {1, 2, 3, 4, 5};
    	int* begin = myArray;
    	int* end = myArray + sizeof(myArray) / sizeof(myArray[0]);

		sp2.addNumbers(begin, end);

		std::cout << std::endl;

		sp2.printSet();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
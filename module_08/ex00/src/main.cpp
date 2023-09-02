/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:07:46 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/02 21:21:02 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.tpp"
#include <iostream>
#include <vector>

int	main(void)
{
	try
	{
		std::vector<int>			tab;
		std::vector<int>::iterator	it;

		for (int i = 0; i < 5; i++)
			tab.push_back(i + 1);

		for (it = tab.begin(); it != tab.end(); it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (it = easyfind(tab, 3); it != tab.end(); it++)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		it = easyfind(tab, 6);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

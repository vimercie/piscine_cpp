/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:06:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/16 03:16:04 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <string>

int main()
{
	int 		int_tab[] = {0, 1, 2, 3, 4};
	char		char_tab[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	str_tab[] = {"Hello", "World", "!"};

	iter(int_tab, 5, print);
	std::cout << std::endl;
	iter(char_tab, 5, print);
	std::cout << std::endl;
	iter(str_tab, 3, print);
	return 0;
}
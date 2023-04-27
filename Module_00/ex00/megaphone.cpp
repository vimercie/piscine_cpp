/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:55:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/28 00:07:09 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	print_all_caps(char *str)
{
	int	i = 0;
	while (str[i])
	{
		std::cout << (char)toupper(str[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			print_all_caps(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}

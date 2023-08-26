/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:04:57 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/26 14:54:03 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat peon("Peon", 150);
		// Bureaucrat b3("b3", 151);
		// Bureaucrat b4("b4", 0);

		std::cout << boss << std::endl;
		std::cout << peon << std::endl;

		// boss.incrementGrade();
		// peon.decrementGrade();
		boss.decrementGrade();
		peon.incrementGrade();

		std::cout << boss << std::endl;
		std::cout << peon << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
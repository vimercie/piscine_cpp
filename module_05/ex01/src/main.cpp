/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:04:57 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/08 03:38:41 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	try
	{
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	peon("Peon", 150);
		Form		form("Form", 1, 1);
		// Form		form2("Form2", 151, 1);
		// Form		form3("Form3", 0, 1);
		// Form		form4("Form4", 1, 151);
		// Form		form5("Form5", 1, 0);

		std::cout << std::endl;

		std::cout << boss << std::endl;
		std::cout << peon << std::endl;
		std::cout << form << std::endl;

		std::cout << std::endl;

		peon.signForm(form);
		boss.signForm(form);
		boss.signForm(form);

		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
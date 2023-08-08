/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:04:57 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/08 05:20:47 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat				boss("Boss", 1);
		Bureaucrat				peon("Peon", 150);
		ShrubberyCreationForm	form("garden");
		RobotomyRequestForm		form2("robot");
		PresidentialPardonForm	form3("president");

		std::cout << std::endl;

		std::cout << boss << std::endl;
		std::cout << peon << std::endl;
		std::cout << form << std::endl;

		std::cout << std::endl;

		peon.signForm(form);
		boss.signForm(form);
		boss.signForm(form);
		boss.signForm(form2);
		boss.signForm(form3);

		std::cout << std::endl;

		peon.executeForm(form);
		boss.executeForm(form);
		boss.executeForm(form2);
		boss.executeForm(form3);
		
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
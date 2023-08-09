/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:04:57 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/09 03:08:52 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	try
	{
		Intern	intern;
		std::cout << std::endl;
		Form*	form1 = intern.makeForm("shrubbery creation", "garden");
		Form*	form2 = intern.makeForm("robotomy request", "Bender");
		Form*	form3 = intern.makeForm("presidential pardon", "Zaphod");
		// Form*	form4 = intern.makeForm("unknown", "unknown");

		std::cout << std::endl;

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		// std::cout << *form4 << std::endl;

		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
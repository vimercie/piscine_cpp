/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 03:04:57 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/27 20:12:13 by vimercie         ###   ########lyon.fr   */
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
	Intern	intern;
	Intern	intern2 = intern;

	std::cout << std::endl;

	Form*	form1 = intern.makeForm("shrubbery creation", "garden");
	Form*	form2 = intern2.makeForm("robotomy request", "Bender");
	Form*	form3 = intern.makeForm("presidential pardon", "Zaphod");
	Form*	form4 = intern2.makeForm("unknown", "unknown");

	if (!form1 || !form2 || !form3 || !form4)
	{
		delete form1;
		delete form2;
		delete form3;
		delete form4;
		return (1);
	}

	std::cout << std::endl;

	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;
	std::cout << *form4 << std::endl;

	std::cout << std::endl;

	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 01:41:53 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/27 20:10:24 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/Form.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern()
{
	this->names[0] = "shrubbery creation";
	this->names[1] = "robotomy request";
	this->names[2] = "presidential pardon";

	this->ptr_tab[0] = &Intern::makeShrubberyCreationForm;
	this->ptr_tab[1] = &Intern::makeRobotomyRequestForm;
	this->ptr_tab[2] = &Intern::makePresidentialPardonForm;

	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	*this = src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& src)
{
	if (this == &src)
		return *this;

	for (int i = 0; i < 3; i++)
		this->names[i] = src.names[i];
	for (int i = 0; i < 3; i++)
		this->ptr_tab[i] = src.ptr_tab[i];

	std::cout << "Intern assignment operator called" << std::endl;

	return *this;
}

Form*	Intern::makeForm(const std::string& name, const std::string& target)
{
	Form*	formPtr;

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(this->names[i]) == 0)
		{
			formPtr = (this->*ptr_tab[i])(target);
			std::cout << "Intern creates " << formPtr->getName() << std::endl;
			return formPtr;
		}
	}
	std::cout << "Form not found" << std::endl;
	return NULL;
}

Form*	Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

Form*	Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

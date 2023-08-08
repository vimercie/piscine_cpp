/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:03:30 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/08 05:08:30 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
	this->setTarget(src.getTarget());
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this == &src)
		return (*this);

	this->setIsSigned(src.getIsSigned());
	this->setTarget(src.getTarget());

	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::runForm() const
{
	std::string		file_name = this->getTarget() + "_shrubbery";
	std::ofstream	ofs(file_name.c_str());

	if (!ofs.is_open())
		throw std::runtime_error("Can't open file");

	ofs << "	   ###" << std::endl;
	ofs << "      #o###" << std::endl;
	ofs << "    #####o###" << std::endl;
	ofs << "   #o#\\#|#/###" << std::endl;
	ofs << "    ###\\|/#o#" << std::endl;
	ofs << "     # }|{  #" << std::endl;
	ofs << "       }|{" << std::endl;
}

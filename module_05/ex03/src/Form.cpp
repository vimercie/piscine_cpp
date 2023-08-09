/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:23:13 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/09 03:06:19 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150), target("default")
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target("default")
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& src) : name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form& src)
{
	if (this == &src)
		return (*this);

	this->setIsSigned(src.getIsSigned());
	this->setTarget(src.getTarget());

	std::cout << "Form assignment operator called" << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& src)
{
	os << src.getName();
	os << ", form gradeToSign " << src.getGradeToSign();
	os << ", gradeToExecute " << src.getGradeToExecute();
	os << ", signed: " << src.getIsSigned();
	return (os);
}

const std::string&	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

const std::string&	Form::getTarget() const
{
	return (this->target);
}

void	Form::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;
}

void	Form::setTarget(const std::string& target)
{
	this->target = target;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (this->isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void	Form::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	this->runForm();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

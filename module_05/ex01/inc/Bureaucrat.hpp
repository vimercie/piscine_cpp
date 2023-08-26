/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:38:15 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/26 14:57:51 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	Form;

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat&		operator=(const Bureaucrat& src);

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int grade);
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(class Form& f);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& 	operator<<(std::ostream& os, const Bureaucrat& src);

#endif
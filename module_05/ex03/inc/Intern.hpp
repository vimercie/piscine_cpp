/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 01:37:26 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/09 03:07:35 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>

class	Form;
class	ShrubberyCreationForm;
class	RobotomyRequestForm;
class	PresidentialPardonForm;

class	Intern
{
	private:
		typedef Form*	(Intern::*ft_ptr)(const std::string& target);

		std::string	names[3];
		ft_ptr		ptr_tab[3];
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();

		Intern&	operator=(const Intern& src);

		Form*	makeForm(const std::string& name, const std::string& target);
		Form*	makeShrubberyCreationForm(const std::string& target);
		Form*	makeRobotomyRequestForm(const std::string& target);
		Form*	makePresidentialPardonForm(const std::string& target);
		
		class	FormNotFoundException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

#endif
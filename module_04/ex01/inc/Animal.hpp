/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:24:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 16:40:10 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& src);
		virtual	~Animal();

		Animal&				operator=(const Animal& src);

		const std::string&	getType() const;
		void				setType(const std::string src);

		virtual void		makeSound() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:16:33 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 17:09:07 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(const Dog& src);
		~Dog();

		Dog&			operator=(const Dog& src);

		virtual void	makeSound() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:16:31 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/30 16:06:03 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		virtual	~Cat();

		Cat&			operator=(const Cat& src);

		virtual void	makeSound() const;
};

#endif
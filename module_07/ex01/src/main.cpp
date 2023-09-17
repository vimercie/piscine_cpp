/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 03:06:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/18 01:01:50 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <string>

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 		private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// int main()
// {
// 	int		tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome	tab2[5];

// 	iter( tab, 5, print );
// 	iter( tab2, 5, print );
// 	return 0;
// }

int main()
{
	int 		int_tab[] = {0, 1, 2, 3, 4};
	char		char_tab[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	str_tab[] = {"Hello", "World", "!"};

	iter(int_tab, 5, print);
	std::cout << std::endl;
	iter(char_tab, 5, print);
	std::cout << std::endl;
	iter(str_tab, 3, print);
	return 0;
}
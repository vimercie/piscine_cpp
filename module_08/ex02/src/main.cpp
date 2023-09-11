/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:58:03 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/12 00:59:59 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top() = " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mstack.size() = " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << std::endl;

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	return 0;
}

// int main()
// {
// 	std::list<int>	list;

// 	list.push_back(5);
// 	list.push_back(17);
	
// 	std::cout << "list.back() = " << list.back() << std::endl;
	
// 	list.pop_back();
	
// 	std::cout << "list.size() = " << list.size() << std::endl;
	
// 	list.push_back(3);
// 	list.push_back(5);
// 	list.push_back(737);
// 	//[...]
	
// 	list.push_back(0);

// 	std::cout << std::endl;

// 	std::list<int>::iterator	it = list.begin();
// 	std::list<int>::iterator	ite = list.end();
	
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::list<int>	s(list);

// 	return 0;
// }
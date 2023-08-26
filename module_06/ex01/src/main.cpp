/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:36:39 by vimercie          #+#    #+#             */
/*   Updated: 2023/08/14 13:50:58 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.h"

int main()
{
	Data	data;
	uintptr_t	raw;

	data.s1 = "Hello";
	data.s2 = "World";
	data.n = 42;

	raw = Serializer::serialize(&data);
	std::cout << "raw: " << raw << std::endl;

	std::cout << std::endl;

	Data	*data2 = Serializer::deserialize(raw);
	std::cout << "data2->s1: " << data2->s1 << std::endl;
	std::cout << "data2->s2: " << data2->s2 << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;

	return 0;
}
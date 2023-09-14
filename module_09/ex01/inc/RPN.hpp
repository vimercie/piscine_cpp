/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:46:44 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/14 18:39:46 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define ADD 0
# define SUB 1
# define MUL 2
# define DIV 3

# include <iostream>
# include <string>
# include <stack>
# include <cmath>

class	RPN
{
	private:
		RPN();
		RPN(const RPN& src);

		typedef double	(RPN::*ft_ptr)(double, double);

		void	parseRPN(const std::string& str);
		void	calculate(char op);
		double	add(double num1, double num2);
		double	substract(double num1, double num2);
		double	multiply(double num1, double num2);
		double	divide(double num1, double num2);
		bool	isOperator(char c) const;
		bool	ft_isspace(char c);


		std::stack<double>	stack;
		ft_ptr				operations[4];
		std::string			operators;
	public:
		RPN(const std::string& str);
		~RPN();

		RPN&	operator=(const RPN& src);
};


#endif
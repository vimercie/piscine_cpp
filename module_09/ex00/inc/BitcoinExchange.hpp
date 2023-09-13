/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:03:36 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/14 00:22:21 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define PRICES 0
# define RATES 1

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <cstdlib>
# include <map>
# include <stdexcept>

typedef typename std::multimap<std::string, double> BCmap;

class	BitcoinExchange
{
	public:
		BitcoinExchange(char *filename);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& src);
	private:
		BitcoinExchange();

		BCmap		parseBCmap(const std::string& filename, bool type);
		std::string	parseDate(std::string line);
		double		parsePrice(std::string line);
		double		parseRate(std::string line);
		std::string	findClosestDate(std::string date);
		bool		isDateFormatted(std::string date);

		BCmap	rates;
		BCmap	prices;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:03:16 by vimercie          #+#    #+#             */
/*   Updated: 2023/09/14 00:10:13 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *filename)
{
	rates = parseBCmap("data.csv", RATES);
	prices = parseBCmap(filename, PRICES);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{
		this->rates = src.rates;
		this->prices = src.prices;
	}
	return *this;
}

BCmap	BitcoinExchange::parseBCmap(const std::string& filename, bool type)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");

	BCmap		res;
	std::string	line;
	std::string	date;
	double		value;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		try
		{
			date = parseDate(line);
			if (type == RATES)
				value = parseRate(line);
			if (type == PRICES)
				value = parsePrice(line);

			res.insert(std::make_pair(date, value));

			if (type == PRICES)
			{
				std::cout << date << " => " << value;
				std::cout << " = " <<  value * rates.find(findClosestDate(date))->second << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	file.close();
	return res;
}

std::string	BitcoinExchange::parseDate(std::string line)
{
	std::string	res;

	if (line.find(',') != std::string::npos)
		res = line.substr(0, line.find(','));
	else if (line.find(' ') != std::string::npos)
		res = line.substr(0, line.find(' '));
	else if (line.find('|') != std::string::npos)
		res = line.substr(0, line.find('|'));

	if (!isDateFormatted(res))
		throw std::runtime_error("invalid date format");
	return res;
}

double	BitcoinExchange::parsePrice(std::string line)
{
	if (line.substr(10, 3) != " | ")
		throw std::runtime_error("invalid price format");

	std::string	value = line.substr(13, line.find(' ', 13) - 13);
	double		res = atof(value.c_str());

	for (size_t	i = 0; i < value.length(); i++)
	{
		bool dot = false;

		if (value[i] == '.')
		{
			if (dot)
				throw std::runtime_error("invalid price format");
			dot = true;
		}
		if (!isdigit(value[i]) && value[i] != '.')
			throw std::runtime_error("invalid price format");
	}
	if (res < 0 || res > 1000)
		throw std::runtime_error("invalid price format");

	return res;
}

double	BitcoinExchange::parseRate(std::string line)
{
	if (line[10] != ',')
		throw std::runtime_error("invalid rate format");

	std::string	value = line.substr(11, line.length() - 11);
	double		res = atof(value.c_str());

	for (size_t	i = 0; i < value.length(); i++)
	{
		bool dot = false;

		if (value[i] == '.')
		{
			if (dot)
				throw std::runtime_error("invalid rate format");
			dot = true;
		}
		if (!isdigit(value[i]) && value[i] != '.')
			throw std::runtime_error("invalid rate format");
	}

	return res;
}

bool	BitcoinExchange::isDateFormatted(std::string date)
{
	if (date.length() != 10)					// Parsing du format
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	if (date.substr(0, 10) < "2009-01-02"		// Parsing des années
		|| date.substr(0, 10) > "2022-03-29"

		|| date.substr(5, 2) < "01"				// Parsing des mois
		|| date.substr(5, 2) > "12"

		|| date.substr(8, 2) < "01"				// Parsing des jours
		|| date.substr(8, 2) > "31"
		|| (date.substr(8, 2) > "30"
			&& (date.substr(5, 2) == "04"
			|| date.substr(5, 2) == "06"
			|| date.substr(5, 2) == "09"
			|| date.substr(5, 2) == "11"))

		|| (date.substr(8, 2) > "29"			// Parsing des années bissextiles
			&& date.substr(5, 2) == "02"
			&& (date.substr(0, 4) == "2012"
				|| date.substr(0, 4) == "2016"
				|| date.substr(0, 4) == "2020"))
		|| (date.substr(8, 2) > "28"
			&& date.substr(5, 2) == "02"
			&& (date.substr(0, 4) != "2012"
				&& date.substr(0, 4) != "2016"
				&& date.substr(0, 4) != "2020")))
		return false;
	return true;
}

std::string	BitcoinExchange::findClosestDate(std::string date)
{
	BCmap::iterator it = rates.begin();
	std::string	res;

	while (it != rates.end())
	{
		if (it->first > date)
			break;
		res = it->first;
		it++;
	}

	return res;
}

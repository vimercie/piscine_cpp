/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:51:10 by vimercie          #+#    #+#             */
/*   Updated: 2023/07/16 22:01:20 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static bool	isalnum_str(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isalnum(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	fileCpy(std::string file, std::string content)
{
	std::string	outfile_name = file;
	outfile_name.append(".replace");
	std::ofstream outfile(outfile_name.c_str());

	if (!outfile.is_open())
	{
		std::cout << "Error occured while creating outfile" << std::endl;
		return ;
	}
	outfile << content;
}

std::string	fileToStr(char *filename)
{
	std::ifstream		file(filename);
	std::stringstream	buffer;

	if (file.bad())
		return (NULL);
	buffer << file.rdbuf();
	file.close();
	return (buffer.str());
}

std::string	replaceStr(std::string str, std::string s1, std::string s2)
{
	std::string res = "";
	size_t		index = 0;

	while (str.begin() + index != str.end())
	{
		if (str.compare(index, s1.size(), s1) == 0)
		{
			if (!s2.empty())
				res.append(s2);
			index += s1.size();
		}
		else
		{
			res.push_back(str[index]);
			index++;
		}
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./ex04 [filename] [s1] [s2]" << std::endl;
		return (0);
	}

	std::string	infile = fileToStr(av[1]);
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	if (infile.empty() || s1.empty()
		|| !isalnum_str(s1) || !isalnum_str(s2))
	{
		std::cout << "Invalid arguments" << std::endl;
		return (0);
	}
	fileCpy(av[1], replaceStr(infile, s1, s2));
	return (1);
}

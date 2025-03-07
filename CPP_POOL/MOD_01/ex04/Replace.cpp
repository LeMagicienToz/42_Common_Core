/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:34:40 by muteza            #+#    #+#             */
/*   Updated: 2023/09/18 13:04:55 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
{
	this->_file = filename;
	this->_s1 = s1;
	this->_s2 = s2;
	
	this->_filerep = filename + ".replace";
}

void Replace::sedReplace()
{
	std::string		line;
	std::ofstream	writer(this->_filerep); // * Open() ou force create puis open() le fichier avec '.replace'
	std::ifstream	infile(this->_file); // * Open() le fichier existant 

	if (infile.fail())
	{
		std::cout << "File doesn't exist" << std::endl;
		return ;
	}
	if (infile.bad())
	{
		std::cout << "cannot open the file" << std::endl;
		return ;
	}
	while(infile.good()) //true tant qu'il n'y a pas de eof de fail(1) ou bad(1)
	{
		getline(infile, line, '\n');

		while (line.find(this->_s1) != std::string::npos && !this->_s1.empty())
		{
			line.insert(line.find(this->_s1), this->_s2);
			line.erase(line.find(this->_s1), this->_s1.size());
		}
		if (!infile.eof())
			line += '\n';
		writer.write(line.c_str(), line.size());
	}
}

Replace::~Replace()
{
	
}
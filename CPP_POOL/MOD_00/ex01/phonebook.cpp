/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:12:17 by muteza            #+#    #+#             */
/*   Updated: 2023/07/15 16:24:02 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Phonebook.hpp"

#define MAX_CONTACT 8

PhoneBook::PhoneBook(void) {

	this->index = 0;
	this->index_max = 0;
}


int PhoneBook::ft_isdigit(const char *str){
	
	if (!str || str == NULL)
		return (0);
	for(int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int PhoneBook::ft_isalpha(const char *str){
	
	for(int i = 0; str[i]; i++)
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			return (0);
	}
	return (1);
}

void PhoneBook::add_contact(void) {
	
	std::string str;

	if (this->index == MAX_CONTACT)
	{
		this->index = 0;
		std::cout << "Max contact reach" << std::endl;
	}
	while (str.empty())
	{
		std::cout << "lastName : ";
		std::getline (std::cin,str);
		if (std::cin.fail())
			exit(0);
		if (ft_isalpha(str.c_str()) == 0)
		{
			str.clear();
			std::cout << "Error can only use letters" << std::endl;	
		}
		else
			this->contact[this->index].set_lastName(str);	
	}
	str.clear();
	while (str.empty())
	{
		std::cout << "firstName : ";
		std::getline (std::cin,str);
		if (std::cin.fail())
			exit(0);
		if (ft_isalpha(str.c_str()) == 0)
		{
			str.clear();
			std::cout << "Error can only use letters" << std::endl;	
		}
		else
			this->contact[this->index].set_firstName(str);	
	}
	str.clear();
	while (str.empty())
	{
		std::cout << "nickName : ";
		std::getline (std::cin,str);
		if (std::cin.fail())
			exit(0);
		if (ft_isalpha(str.c_str()) == 0)
		{
			str.clear();
			std::cout << "Error can only use letters" << std::endl;	
		}
		else
			this->contact[this->index].set_nickName(str);	
	}
	str.clear();
	while (str.empty())
	{
		std::cout << "Number : ";
		std::getline (std::cin,str);
		if (std::cin.fail())
			exit(0);
		if (ft_isdigit(str.c_str()) == 0)
		{
			str.clear();
			std::cout << "Error can only use Number" << std::endl;	
		}
		else
			this->contact[this->index].set_number(str);
	}
	str.clear();
	while (str.empty())
	{
		std::cout << "Darkest secret : ";
		std::getline (std::cin,str);
		if (std::cin.fail())
			exit(0);
		this->contact[this->index].set_darksecret(str);
	}
	if (this->index_max == MAX_CONTACT)
		this->index++;
	else
	{	
		this->index++;
		this->index_max++;
	}
	
}


void PhoneBook::search_contact(void) {

	std::string str;
	for (int j = 0; j != 45; j++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int j = 0; j != 45; j++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < this->index_max ; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		str = this->contact[i].get_firstName();
		if (str.size() > 10)
		{
			str.erase(str.begin() + 9, str.end());
			str.push_back('.');
		}
		std::cout << std::setw(10) << str << "|";
		str = this->contact[i].get_lastName();
		if (str.size() > 10)
		{
			str.erase(str.begin() + 9, str.end());
			str.push_back('.');
		}
		std::cout << std::setw(10) << str << "|";
		str = this->contact[i].get_nickName();
		if (str.size() > 10)
		{
			str.erase(str.begin() + 9, str.end());
			str.push_back('.');
		}
		std::cout << std::setw(10) << str << "|";
		std::cout << std::endl;
		for (int j = 0; j != 45; j++)
		std::cout << "-";
		std::cout << std::endl;
	}
	str.clear();
	while (str.empty() && this->index > 0)
	{
		std::cout << "Select index : ";
		std::getline (std::cin,str);
		if (std::cin.fail())
			exit(0);
		if (str.empty())
			std::cout << "Missing outpout " << std::endl;
		else
		{
			if (ft_isdigit(str.c_str()) == 0)
			{
				str.clear();
				std::cout << "Error can only use Number" << std::endl;	
			}
			else if (this->index_max >= (std::stoi(str) + 1))
			{
				std::cout << std::endl;
				std::cout << "Last Name : " << this->contact[std::stoi(str)].get_lastName() << std::endl;
				std::cout << "First Name : " << this->contact[std::stoi(str)].get_firstName() << std::endl;
				std::cout << "Nick Name : " << this->contact[std::stoi(str)].get_nickName() << std::endl;
				std::cout << "Number : " << this->contact[std::stoi(str)].get_number() << std::endl;
				std::cout << "Darkest secret : " << this->contact[std::stoi(str)].get_darksecret() << std::endl;
			}
			else
			{
				std::cout << "Invalide Number" << std::endl;
				str.clear();
			}
		}
	}
}

void PhoneBook::input(void) {

	std::string str;
	
	while (str.empty())
	{
		std::cout << "$_$ -> ";
		std::getline (std::cin,str);
		if (std::cin.fail()) 
			exit(0);
		if (str.compare("ADD") == 0)
			add_contact();
		if (str.compare("SEARCH") == 0)
			search_contact();
		if (str.compare("EXIT") != 0)	
			str.clear();
		else
			exit(0);
	}
	std::cout << str << std::endl;
	
}

PhoneBook::~PhoneBook(void) {

	std::cout << "destructor called" << std::endl;
}

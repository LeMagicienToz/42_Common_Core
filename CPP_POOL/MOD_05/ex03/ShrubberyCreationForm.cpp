/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:02:36 by muteza            #+#    #+#             */
/*   Updated: 2023/11/08 04:55:04 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name): Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = name;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): Form("ShrubberyCreationForm", 145, 137)
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw Form::NotSigned();
	else if (this->getGradeSign() < executor.getGrade())
		throw Form::GradeTooLowException();
	else
	{
		int height = 10;
	   	for (int i = 1; i <= height; i++) {
		for (int j = 0; j < height - i; j++) {
			std::cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
		}
	}
}

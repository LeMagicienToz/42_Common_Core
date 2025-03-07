/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 04:40:29 by muteza            #+#    #+#             */
/*   Updated: 2023/11/08 04:57:50 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const name): Form("RobotomyRequestForm", 72, 45)
{
	this->_target = name;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form("RobotomyRequestForm", 72, 45)
{
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw Form::NotSigned();
	else if (this->getGradeSign() < executor.getGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::srand(std::time(0));
		if (rand() % 2)
			std::cout << this->_target << " Get Robotomized" << std::endl;
		else
			std::cout << this->_target << " Failed to get Robotomized" << std::endl;
	}
}
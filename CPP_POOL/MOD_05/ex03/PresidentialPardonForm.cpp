/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:58:30 by muteza            #+#    #+#             */
/*   Updated: 2023/11/08 04:58:38 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const name): Form("PresidentialPardonForm", 25, 5)
{
	this->_target = name;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): Form("PresidentialPardonForm", 25, 5)
{
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw Form::NotSigned();
	else if (this->getGradeSign() < executor.getGrade())
		throw Form::GradeTooLowException();
	else
		std::cout << this->_target << " was forgiven by LE Z." << std::endl;
	return ;
}
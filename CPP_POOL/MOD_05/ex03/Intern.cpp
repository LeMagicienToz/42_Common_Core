/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:03:38 by muteza            #+#    #+#             */
/*   Updated: 2023/11/08 05:04:45 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <exception>
#include <string>

Intern::Intern()
{
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return ;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

Form *Intern::makeForm(std::string const & typeForm, std::string const & target) const
{
	std::string formList[3] = {"presidential pardon",
								"robotomy request",
								"shrubbery creation"};

	for (int i = 0; i < 3; i++)
		if (!formList[i].compare(typeForm))
		{
			switch (i)
			{
				case 0: return (new PresidentialPardonForm(target));
				case 1: return (new RobotomyRequestForm(target));
				case 2: return (new ShrubberyCreationForm(target));
			}
		}
	throw Intern::InternException();
	return (NULL);
}

const char* Intern::InternException::what() const throw()
{
	return ("Form is not found");
}
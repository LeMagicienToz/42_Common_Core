/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:07:52 by muteza            #+#    #+#             */
/*   Updated: 2023/11/08 05:09:25 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;
		Form * maison;
		Form * walle;
		Form * sarkozy;
		Form * blender;
		Bureaucrat sean(1, "Sean Paul");

		(void)blender;
		maison 	= someRandomIntern.makeForm("shrubbery creation", "Maison");
		walle 	= someRandomIntern.makeForm("robotomy request", "Wall-E");
		sarkozy = someRandomIntern.makeForm("presidential pardon", "Sarkozy");
		// blender = someRandomIntern.makeForm("blender", "Blender");
		
		std::cout << sean << std::endl;
		std::cout << *maison << std::endl;
		std::cout << *walle << std::endl;
		std::cout << *sarkozy << std::endl;

		sean.signForm(*maison);
		maison->beSigned(sean);

		sean.signForm(*walle);
		walle->beSigned(sean);
		
		sean.signForm(*sarkozy);
		sarkozy->beSigned(sean);

		std::cout << *maison << std::endl;
		std::cout << *walle << std::endl;
		std::cout << *sarkozy << std::endl;

		sean.executeForm(*maison);
		maison->execute(sean);

		sean.executeForm(*walle);
		walle->execute(sean);

		sean.executeForm(*sarkozy);
		sarkozy->execute(sean);
				
		delete maison;
		delete walle;
		delete sarkozy;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
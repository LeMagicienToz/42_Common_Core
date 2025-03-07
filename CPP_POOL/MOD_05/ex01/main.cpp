/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:07:54 by muteza            #+#    #+#             */
/*   Updated: 2023/10/25 15:47:56 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
   try
	{
		Form		xc33("pinard 5ans d'age", 15, 1);
		Form		xc34("pinard 10 ans d'age", 51, 1);
		Bureaucrat sean(50, "Gerard depardieux");
		
		std::cout << sean << std::endl;
		std::cout << xc33 << std::endl;
		std::cout << xc34 << std::endl;

		// sean.signForm(xc33);
		sean.signForm(xc34);
		// xc33.beSigned(sean);
		xc34.beSigned(sean);

		std::cout << xc33 << std::endl;
		std::cout << xc34 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
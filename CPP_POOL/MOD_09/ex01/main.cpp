/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:05:55 by muteza            #+#    #+#             */
/*   Updated: 2024/08/19 19:12:03 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Bad numbers of arguments." << std::endl;
		return (0);
	}

	try
	{
		std::stringstream str1(av[1]);
		RPN rpn(str1);
		rpn.calculate();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

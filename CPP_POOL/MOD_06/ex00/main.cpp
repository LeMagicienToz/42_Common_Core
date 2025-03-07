/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:07:54 by muteza            #+#    #+#             */
/*   Updated: 2023/12/08 13:21:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	try 
	{
		if (ac == 2)
		{
			ScalarConverter c(av[1]);
			std::cout << c;
		}
		else
			std::cout << "\033[1;31mError : Wrong number of Args\033[0m" << std::endl;
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
		return 1;
	}

    return 0;
}

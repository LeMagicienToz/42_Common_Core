/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:02:10 by muteza            #+#    #+#             */
/*   Updated: 2023/09/25 05:33:48 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl	Harl;

	Harl.complain("DEBUG");
	std::cout << std::endl;

	Harl.complain("INFO");
	std::cout << std::endl;

	Harl.complain("WARNING");
	std::cout << std::endl;

	Harl.complain("ERROR");
	std::cout << std::endl;

	Harl.complain("invalid level");
	std::cout << std::endl;

	Harl.complain("");
	std::cout << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:20:24 by muteza            #+#    #+#             */
/*   Updated: 2023/09/25 05:33:38 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    
}

Harl::~Harl()
{
    
}

void	Harl::debug( void ) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger." << std::endl;
	std::cout << "I really do !";
	std::cout << std::endl;

	return ;
}

void	Harl::info( void ) {

	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !";
	std::cout << std::endl;

	return ;
}

void	Harl::warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;

	return ;
}

void	Harl::error( void ) {

	std::cout << "This is unacceptable ! I want to speak to the manager now.";
	std::cout << std::endl;

	return ;
}

void    Harl::complain(std::string level)
{
    std::string tab_level[4]= {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr_functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
    while (i < 4 && level != tab_level[i]) {
        i++;
    }
    if (i < 4) {
        (this->*ptr_functions[i])();
    } else {
        std::cout << "Harl d'ont have any complain" << std::endl;
    }
}
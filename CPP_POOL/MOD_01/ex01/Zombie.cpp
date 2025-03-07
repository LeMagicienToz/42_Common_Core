/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:04:20 by muteza            #+#    #+#             */
/*   Updated: 2023/08/16 17:26:17 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructeur call" << std::endl;
}

void    Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::announce(void) const{

	std::cout << this->_name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::get_Name(void) const
{
	return (this->_name);
}

Zombie::~Zombie(void)
{
	std::cout << "Destructeur call" << std::endl;
}

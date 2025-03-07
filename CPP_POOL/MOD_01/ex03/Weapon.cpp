/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:10:16 by muteza            #+#    #+#             */
/*   Updated: 2023/09/07 08:26:19 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string bat){

	if (bat.empty())
		this->_type = "Hands";
	else
		this->_type = bat;
	
}

Weapon::~Weapon(){
}

void Weapon::setType(std::string newtype)
{
	this->_type = newtype;
}

const std::string& Weapon::getType() const
{
	return(this->_type);
}
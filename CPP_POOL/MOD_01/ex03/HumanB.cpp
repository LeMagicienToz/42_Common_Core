/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:33:26 by muteza            #+#    #+#             */
/*   Updated: 2023/09/07 08:38:26 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
}

void HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weap->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weap)
{
    this->_weap = &weap;
}

HumanB::~HumanB(){
}
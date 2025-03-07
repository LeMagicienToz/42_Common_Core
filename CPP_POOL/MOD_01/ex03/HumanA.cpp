/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:55:21 by muteza            #+#    #+#             */
/*   Updated: 2023/09/07 08:30:34 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &p) : _name(name), _weap(p){
}

void HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weap.getType() << std::endl;
}

HumanA::~HumanA(){
}

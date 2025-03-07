/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:42:56 by muteza            #+#    #+#             */
/*   Updated: 2023/08/15 18:57:01 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	Zombie::randomChump(std::string name) {

    //ne peut pas sortir du scop
	Zombie zombou(name);
    zombou._name = name;
    zombou.announce();
}
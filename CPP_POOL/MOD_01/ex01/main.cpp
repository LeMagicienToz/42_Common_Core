/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:04:41 by muteza            #+#    #+#             */
/*   Updated: 2023/09/27 09:54:24 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //creation horde de ZOMBIIIE
    Zombie *horde = zombieHorde(4, "Zomb");; 

    for (int i = 0; i < 4; i++)
    {
        horde[i].announce();
    }
    delete [] horde;
}
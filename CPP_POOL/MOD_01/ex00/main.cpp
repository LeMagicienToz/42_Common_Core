/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:08:34 by muteza            #+#    #+#             */
/*   Updated: 2023/08/14 05:49:50 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	//init name if no Zombies are created
	Zombie	instance("first_Zomb");

	//(malloc)
	Zombie	*zombTwo = instance.newZombie("snd_Zomb");

	//(stack)
	instance.randomChump("third_Zomb");

	zombTwo->announce();
	delete zombTwo;
}

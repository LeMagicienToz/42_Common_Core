/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:33:42 by muteza            #+#    #+#             */
/*   Updated: 2023/10/04 19:16:13 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main ()
{
	// ClapTrap def;
	// ClapTrap John_wick("Jhon Wick");

	ClapTrap maxou("maxou");
	ClapTrap mechant("mechant");

	maxou.attack("mechant");
	mechant.beRepaired(100);
	mechant.takeDamage(100);

	ScavTrap scav("scav");

	scav.attack("maxou");
	scav.beRepaired(100);
	scav.takeDamage(100);
	scav.guardGate();

}

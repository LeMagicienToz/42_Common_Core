/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:33:42 by muteza            #+#    #+#             */
/*   Updated: 2023/10/05 10:25:40 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap frag("frag");

	frag.attack("clap");
	frag.beRepaired(100);
	frag.takeDamage(100);
	frag.highFivesGuys();

}

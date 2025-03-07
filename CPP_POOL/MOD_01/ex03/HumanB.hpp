/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:29:26 by muteza            #+#    #+#             */
/*   Updated: 2023/09/07 08:38:44 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB(void);
        void setWeapon(Weapon &weap);
        void attack(void) const;
	private:
		std::string _name;
        Weapon *_weap;
};
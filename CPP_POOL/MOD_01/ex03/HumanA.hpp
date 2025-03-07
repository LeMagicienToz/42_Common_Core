/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:51:21 by muteza            #+#    #+#             */
/*   Updated: 2023/09/07 08:23:30 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon &p);
		~HumanA(void);
        void attack(void) const;
	private:
		std::string _name;
        Weapon &_weap;
};
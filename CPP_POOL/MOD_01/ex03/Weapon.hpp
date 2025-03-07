/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:01:52 by muteza            #+#    #+#             */
/*   Updated: 2023/09/07 08:10:59 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon {

	public:
		Weapon(std::string bat);
		~Weapon(void);
		void setType(std::string newtype);
		const std::string &getType() const;
	private:
		std::string _type;
};
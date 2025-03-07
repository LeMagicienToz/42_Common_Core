/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:02:59 by muteza            #+#    #+#             */
/*   Updated: 2023/07/13 15:02:16 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string.h>
#include <iostream>

class Contact {

public:
	std::string get_lastName(void) const;
	void		set_lastName(std::string str);
	std::string get_firstName(void) const;
	void		set_firstName(std::string str);
	std::string get_nickName(void) const;
	void		set_nickName(std::string str);
	std::string get_number(void) const;
	void		set_number(std::string str);
	std::string get_darksecret(void) const;
	void		set_darksecret(std::string str);

private:
	std::string _lastName;
	std::string _firstName;
	std::string _nickName;
	std::string _number;
	std::string _darkestSecret;
};

#endif
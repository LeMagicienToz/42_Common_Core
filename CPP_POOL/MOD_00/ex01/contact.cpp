/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:29:07 by muteza            #+#    #+#             */
/*   Updated: 2023/07/13 14:32:08 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

void	Contact::set_lastName(std::string str){
	this->_lastName = str;
}

std::string Contact::get_lastName(void) const{
	return (this->_lastName);
}

void	Contact::set_firstName(std::string str){
	this->_firstName = str;
}

std::string Contact::get_firstName(void) const{
	return (this->_firstName);
}

void	Contact::set_nickName(std::string str){
	this->_nickName = str;
}

std::string Contact::get_nickName(void) const{
	return (this->_nickName);
}

void	Contact::set_number(std::string str){
	this->_number = str;
}

std::string Contact::get_number(void) const{
	return (this->_number);
}

void	Contact::set_darksecret(std::string str){
	this->_darkestSecret = str;
}

std::string Contact::get_darksecret(void) const{
	return (this->_darkestSecret);
}
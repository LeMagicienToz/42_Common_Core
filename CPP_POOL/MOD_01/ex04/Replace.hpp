/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:29:28 by muteza            #+#    #+#             */
/*   Updated: 2023/09/25 05:19:00 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP
#include <iostream>
#include <fstream>

class Replace {
	
	public:
		Replace(std::string filename, std::string s1, std::string s2);
		~Replace();
		void sedReplace();
	private:
		std::string _filerep;
		std::string _file;
		std::string _s1;
		std::string _s2;
	
};

#endif
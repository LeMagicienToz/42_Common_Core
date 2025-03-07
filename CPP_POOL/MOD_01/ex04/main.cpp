/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:02:10 by muteza            #+#    #+#             */
/*   Updated: 2023/09/18 13:05:41 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error with argument !" << std::endl;
		return 0;
	}
	
	Replace	sed(argv[1], argv[2], argv[3]);
	sed.sedReplace();
	return 0;
}
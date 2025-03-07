/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:36:41 by muteza            #+#    #+#             */
/*   Updated: 2023/08/27 09:58:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    
    std::cout << "addresse de la string en memoire : " << &brain << std::endl;    
    std::cout << "addresse stocke dans le pointeur : " << stringPTR << std::endl;
    std::cout << "addresse stocke dans la reference : " << &stringREF << std::endl;

    std::cout << "valeur de la string en memoire : " << brain << std::endl;    
    std::cout << "valeur pointé par pointeur : " << *stringPTR << std::endl;
    std::cout << "valeur pointé par reference : " << stringREF << std::endl;
}

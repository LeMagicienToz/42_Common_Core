/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:17:39 by muteza            #+#    #+#             */
/*   Updated: 2023/10/15 18:18:59 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		virtual ~Brain(void);

		Brain &	operator=(Brain const & rhs);
		
		std::string	ideas[100];

		void	setIdeas(std::string const ideas, int const i);
		void	viewIdeas(void);
};

#endif
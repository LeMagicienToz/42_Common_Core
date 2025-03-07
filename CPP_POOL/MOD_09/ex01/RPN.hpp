/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:42:49 by muteza            #+#    #+#             */
/*   Updated: 2024/08/19 19:10:11 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>

# include <stdexcept>

# include <algorithm>
# include <stack>

class RPN {

public:
/*CONST / DEST*/
	RPN( std::stringstream &rpn);
	RPN( RPN const &src );
	~RPN( void );
	void calculate();

/*OPERATOR OVERLOAD*/
	RPN	&operator=( RPN const &rhs );

private:

	RPN( void );

	std::stack<int>	stack;

};

#endif
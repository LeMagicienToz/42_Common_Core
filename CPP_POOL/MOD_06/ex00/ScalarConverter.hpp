/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:08:12 by muteza            #+#    #+#             */
/*   Updated: 2023/12/08 13:21:33 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#pragma once

# include <iostream>
# include <exception>
# include <typeinfo>
# include <climits>
# include <cfloat>
# include <cctype>
# include <string>
# include <iomanip>
# include <cerrno>
# include <cstdlib>

class ScalarConverter {

public:

	// Constructor and Destructor
	ScalarConverter(void);
	ScalarConverter( ScalarConverter const &src );
	virtual ~ScalarConverter(void);
	// Additional Constructor
	ScalarConverter ( std::string str );

	// Operator Overload
	ScalarConverter	&operator=( ScalarConverter const &rhs );

	// Getters and Setters
	std::string		getStr( void ) const;
	void			setStr( std::string );

	// member function
	bool			isNumeric( std::string str ) const;
	bool			isDisplayable( std::string str ) const;
	char			toChar( std::string str ) const;
	int				toInt( std::string str ) const;
	float			toFloat( std::string str ) const;
	double			toDouble( std::string str ) const;

	// Exceptions
		class NotANumberException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class NotDisplayableException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class OverflowException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

private:
	std::string _str;
};
std::ostream &	operator<<( std::ostream & o, ScalarConverter const & c );

#endif

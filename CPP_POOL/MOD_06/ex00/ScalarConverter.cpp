/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:18:51 by muteza            #+#    #+#             */
/*   Updated: 2023/12/09 03:56:07 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Constructor Destructor 

ScalarConverter::ScalarConverter( void ) 
{
	std::cout << "Default Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) 
{
    std::cout << "Copy Constructor Called" << std::endl;
	*this =src;
}

ScalarConverter::~ScalarConverter( void ) 
{
	    std::cout << "Default Destructor Called" << std::endl;
}

ScalarConverter::ScalarConverter ( std::string str ) : _str(str)
{
	std::cout << "Convert Constructor called" << std::endl;
	if (!isDisplayable(str))
		throw NotDisplayableException();
}

// Assignement 

ScalarConverter &	ScalarConverter::operator=( const ScalarConverter & rhs )
{
	std::cout << "Convert Assignment operator called" << std::endl;
	this->_str = rhs._str;
	return (*this);
}

// Setter && getter

void	ScalarConverter::setStr( std::string str )
{
	if (!isDisplayable(str))
		throw NotDisplayableException();
	this->_str = str;
}

std::string		ScalarConverter::getStr( void ) const
{
	return (this->_str);
}

//Member function



bool	ScalarConverter::isNumeric( std::string str ) const
{
	bool onedot(false);

	if ( str.empty() )
		return (0);
	for ( unsigned int i(0) ; i < str.size() ; i++ )
	{
		if (str.at(i) == '.')
		{
			if (onedot)
				return (0);
			onedot = true;
		}
		else if (!((i == 0 && (str.at(i) == '-' || str.at(i) == '+')) \
		|| (str.at(i) >= '0' && str.at(i) <= '9') || str.at(i) <= 'e' \
		|| ((i == str.size() - 1) && str.at(i)  == 'f')))
			return (0);
	}
	return (1);
}

bool	ScalarConverter::isDisplayable( std::string str ) const
{
	if ( str.empty() )
		return (0);
	for (unsigned int i(0) ; i < str.size() ; i++)
		if (!isprint(str.at(i)))
			return (0);
	return (1);
}

char	ScalarConverter::toChar( std::string str ) const
{
	if (str.size() == 1 && isDisplayable(str) && !isdigit(str.at(0)))
		return (static_cast<char>(str.at(0)));
	if ((str == "-inff" || str == "+inff" || str == "nanf") \
	|| (str == "-inf" || str == "+inf" || str == "nan"))
		throw NotANumberException();
	if (!isprint(atoi(str.c_str())))
		throw NotDisplayableException();
	return (static_cast<char>(atoi(str.c_str())));
}

int	ScalarConverter::toInt( std::string str ) const
{
	if (str.size() == 1 && isDisplayable(str) && !isdigit(str.at(0)))
		return (static_cast<int>(str.at(0)));
	if ((str == "-inff" || str == "+inff" || str == "nanf") \
	|| (str == "-inf" || str == "+inf" || str == "nan")
	|| (!isNumeric(str)))
		throw NotANumberException();
	if ( atol(str.c_str() ) > INT_MAX || atol(str.c_str() ) < INT_MIN )
		throw OverflowException();
	return (static_cast<int>(atoi(str.c_str())));
}

float	ScalarConverter::toFloat( std::string str ) const
{
	char	*end;

	if (str.size() == 1 && isDisplayable(str) && !isdigit(str.at(0)))
		return (static_cast<float>(str.at(0)));
	if (str == "-inff" || str == "+inff" || str == "nanf" \
	|| str == "-inf" || str == "+inf" || str == "nan")
		return (static_cast<float>(atof(str.c_str())));
	if ( !isNumeric(str) )
		throw NotANumberException();
	strtof(str.c_str(), &end);
	if (((*end != '\0') && (*end != 'f')) || (errno == ERANGE))
		throw OverflowException();
	return (static_cast<float>(strtof(str.c_str(), NULL)));
}

double	ScalarConverter::toDouble( std::string str ) const
{
	char	*end;

	if (str.size() == 1 && isDisplayable(str) && !isdigit(str.at(0)))
		return (static_cast<double>(str.at(0)));
	if (str == "-inff" || str == "+inff" || str == "nanf" \
	|| str == "-inf" || str == "+inf" || str == "nan")
		return (static_cast<double>(atof(str.c_str())));
	if (!isNumeric(str))
		throw NotANumberException();
	strtod(str.c_str(), &end);
	if (((*end != '\0') && (*end != 'f')) || (errno == ERANGE))
		throw OverflowException();
	return (static_cast<double>(strtod(str.c_str(), NULL)));
}

const char* ScalarConverter::NotANumberException::what() const throw()
{
		return ("impossible");
}

const char* ScalarConverter::NotDisplayableException::what() const throw()
{
	return ("Not Displayable");
}

const char* ScalarConverter::OverflowException::what() const throw()
{
	errno = 0;
	return ("Overflow");
}

std::ostream &	operator<<( std::ostream & o, ScalarConverter const & c )
{
	try {
			o << "char : " << c.toChar(c.getStr()) << std::endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;}

	try {
			o << "int : " << c.toInt(c.getStr()) << std::endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;}

	try {
			o << "float : "	;
			float f(c.toFloat(c.getStr()));
			o << f << (f - static_cast<int>(f) == 0 ? ".0" : "") << "f" << std::endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;}

	try {
			o << "double : ";
			double d(c.toDouble(c.getStr()));
			o << d << (d - static_cast<long>(d) == 0 ? ".0" : "") << std::endl; }
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl; }

	return o;
}

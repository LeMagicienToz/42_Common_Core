/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:08:01 by muteza            #+#    #+#             */
/*   Updated: 2024/08/21 13:47:28 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <cctype>
# include <string>

# include <exception>
# include <stdexcept>

# include <algorithm>
# include <map>

class BitcoinExchange {

public:

/*Constructor Destructor */
    BitcoinExchange(const std::string& fileName);
	BitcoinExchange( BitcoinExchange const &src );
	~BitcoinExchange( void );


/*Member function */
	void    exceptionCatch( void ) const;
	void	current(void);
	bool	date_check(std::string const &date) const;
	bool	pairMonthCheck( int const &year, int const &month, int const &day ) const;
	bool	isLeapYear( int const &year ) const ;
	int		valueCheck( std::string const &value ) const;
	static bool	 isNotDigit(char c);	
/* Operator */
	BitcoinExchange	&operator=( BitcoinExchange const &rhs );
	BitcoinExchange( void );

private:



	std::string		_fileName;
	std::ifstream	_input;
	std::ifstream	_csvFile;

	std::map< std::string, float >	_map;

};

#endif
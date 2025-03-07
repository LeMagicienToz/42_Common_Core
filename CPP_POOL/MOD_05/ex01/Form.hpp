/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 08:08:12 by muteza            #+#    #+#             */
/*   Updated: 2023/10/25 15:15:55 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Form {
	public :
			//constructor & destructor
			Form();
			Form(std::string const name, int const gradeSign, int const gradeExec);
			Form(Form const &src);
			virtual ~Form();
			//operator overload
			Form &operator=(Form const &rhs);
			// Accessor
			std::string const	&getName( void ) const;
			int const	&getGradeSign()	const;
			int const	&getGradeExec( void ) const;
			bool const	&getSigned() const;
			// EXECEPTION !
			class GradeTooHighException : public std::exception 
			{
				public:
						virtual const char *what() const throw();
			};
			class GradeTooLowException : public std::exception 
			{
				public:
						virtual const char *what() const throw();
			};
			//Member function
			void	exceptionCheck(void) const;
			void	beSigned(Bureaucrat const &b);
	private :
		std::string const	_name;
		int const	_gradeSign;
		int const _gradeExec;
		bool _signed;
};
//Stream out
std::ostream	&operator<<( std::ostream &o, Form const &i );

#endif

class Form;
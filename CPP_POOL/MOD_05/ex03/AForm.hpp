/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:05 by muteza            #+#    #+#             */
/*   Updated: 2023/11/08 04:53:48 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string const name, int const gradeSign, int const gradeExec);
		Form(Form const & src);
		virtual ~Form(void);

		Form & operator=(Form const & rhs);

		class GradeTooHighException: public std::exception
		{
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char * what() const throw();
		};

		class NotSigned: public std::exception
		{
			public:
				const char * what() const throw();
		};

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;

		void	beSigned(Bureaucrat const & b);

		virtual void execute(Bureaucrat const & executor) const = 0;
	private:
		std::string _name;
		int 		_gradeSign;
		int 		_gradeExec;
		bool		_signed;
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif

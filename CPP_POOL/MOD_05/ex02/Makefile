# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 09:02:27 by muteza            #+#    #+#              #
#    Updated: 2023/11/08 05:06:44 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=		Bureaucrat

SRCS=		main.cpp\
			Bureaucrat.cpp\
			AForm.cpp\
			ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp\
			

OBJS=	$(SRCS:.cpp=.o)

CC=		c++

CXXFLAGS  =	-Wall -Wextra -Werror -std=c++98

all:	$(NAME)
	  
%.o:%.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@printf $$'\033[1m*'

# do:
#     @make $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo $$'\n✅ \033[1;32mproject compiled\033[0m ✅'

library:
			@echo "\n\033[33mcompiling libft\033[0m"
			
clean:
			@rm -f $(OBJS)
			@echo $$'\033[1;31mremoved object files\033[0m'
			
fclean:		clean
			@rm -f $(NAME)
			@echo $$'\033[1;31mremoved $(NAME)\033[0m'


re:	fclean all

.PHONY: all re fclean clean library
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 09:02:27 by muteza            #+#    #+#              #
#    Updated: 2023/12/01 03:45:09 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=		easy_find

SRCS=		main.cpp


OBJS=	$(SRCS:.cpp=.o)

CC=		g++

CXXFLAGS  =	-Wall -Wextra -Werror -std=c++98 -pedantic

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 22:22:41 by muteza            #+#    #+#              #
#    Updated: 2023/08/27 09:45:45 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=           reference

SRCS=           main.cpp\
			
OBJS=           $(SRCS:.cpp=.o)

CC=             c++

CXXFLAGS  =       -Wall -Wextra -Werror -std=c++98

all:            $(NAME)
      
%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $$'\033[1m*'

# do:
# 	@make $(NAME)

$(NAME):                $(OBJS)
			@$(CC) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo $$'\n✅ \033[1;32mproject compiled\033[0m ✅'

library:
			@echo "\n\033[33mcompiling libft\033[0m"
		    
clean:
			@rm -f $(OBJS)
			@echo $$'\033[1;31mremoved object files\033[0m'
		    
fclean:                 clean
			@rm -f $(NAME)
			@echo $$'\033[1;31mremoved $(NAME)\033[0m'


re:                     fclean all
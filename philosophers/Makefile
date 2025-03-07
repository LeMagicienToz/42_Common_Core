# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 15:09:57 by muteza            #+#    #+#              #
#    Updated: 2022/10/03 05:31:01 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=	main.c\
			utils/ft_print.c\
			utils/ft_is_number.c\
			utils/ft_atoi.c\
			utils/ft_atoll.c\
			ini_all.c\
			parcing_thread.c\
			philo_eat.c\
			philo_think.c\
			philo_sleep.c\
		
OBJS	= ${SRCS:.c=.o}

NAME	= philo

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g -pthread $< -o $@ #-fsanitize=address

.c.o:
		${CC} ${CFLAGS} $< -o ${<:.c=.o} 

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re :	fclean all

.PHONY: all clean fclean re

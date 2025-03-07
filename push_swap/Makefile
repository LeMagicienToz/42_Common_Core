SRCS 	=	main.c\
			swap_push.c\
			rotate_rev.c\
			parcing.c\
			parcing_algo.c\
			algo.c\
			algo_little.c\
			utils_algo.c\
			utils/ft_lst.c\
			utils/ft_lst_two.c\
			utils/ft_strjoin.c\
			utils/ft_isdigit.c\
			utils/ft_strncmp.c\
			utils/ft_strlen.c\
			utils/ft_split.c\
			utils/ft_strlcpy.c\
			utils/ft_atoi.c\
			utils/ft_putstr.c\
		
OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g $< -o $@ -fsanitize=address

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

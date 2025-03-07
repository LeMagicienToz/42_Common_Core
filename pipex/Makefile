SRCS 	=	main.c\
			check_access.c\
			prog.c\
			utils/ft_itoa.c\
			utils/ft_putstr.c\
			utils/ft_split.c\
			utils/ft_strlcpy.c\
			utils/ft_strjoin.c\
			utils/ft_strncmp.c\
			utils/ft_strlen.c\
		
OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g $< -o $@ #-fsanitize=address

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

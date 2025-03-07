SRCS =	so_long.c\
		src/files/get_next_line.c\
		src/files/get_next_line_utils.c\
		src/files/ft_calloc.c\
		src/files/ft_split.c\
		src/files/ft_strlcpy.c\
		src/files/ft_strlen_sl.c\
		src/files/ft_strlen_y.c\
		src/files/ft_putstr.c\
		src/files/ft_putnbr.c\
		so_long_two.c\
		so_long_third.c\
		src/files/ft_strlen.c\
		src/mlx/mlx.c\
		src/mlx/print_walk.c\
		src/mlx/ini_pos.c\
		src/mlx/ini_allpos.c\
		src/mlx/put_img.c\
		src/mlx/move.c\
		src/mlx/move_two.c\
		src/mlx/check_col.c\
		so_long_four.c\

		
OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g $< -o $@ -fsanitize=address

.c.o:
		${CC} ${CFLAGS} $< -o ${<:.c=.o} 

$(NAME):
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -lz $(SRCS) -o $(NAME) 

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re :	fclean all

.PHONY: all clean fclean re

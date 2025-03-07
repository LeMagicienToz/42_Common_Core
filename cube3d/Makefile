# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 13:40:09 by muteza            #+#    #+#              #
#    Updated: 2023/06/28 16:47:08 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = cub3D
I_DIR = include
M_MLX = minilibx

SRC =	main.c\
		parsing/init_map.c\
		parsing/check_walls.c\
		parsing/check_args.c\
		parsing/check_all.c\
		parsing/remove_info.c\
		parsing/convert_colors.c\
		parsing/get_face.c\
		parsing/check_infos.c\
		parsing/check_infos_split.c\
		parsing/check_infos_rgb.c\
		parsing/delete_info.c\
		parsing/init_image.c\
		dda/dda_algo.c\
		dda/draw.c\
		dda/draw_two.c\
		dda/door.c\
		dda/movement.c\
		dda/key_pressed.c\
		dda/utils_movement.c\
		dda/mini_map.c\
		utils/ft_strcmp_r.c\
		utils/print_map.c\
		utils/ft_memcpy.c\
		utils/ft_strlen_map.c\
		utils/ft_bzero.c\
		utils/ft_calloc.c\
		utils/ft_split.c\
		utils/ft_strlen_y.c\
		utils/ft_strdup.c\
		utils/ft_strlcpy.c\
		utils/ft_strncmp.c\
		utils/ft_strchr.c\
		utils/ft_atoi.c\
		utils/ft_isdigit.c\
		utils/ft_strlen.c\
		utils/ft_atoi_base.c\

OBJ = $(SRC:%.c=%.o)

all: cube.h $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) -I$(I_DIR) -L$(M_MLX) #-fsanitize=address

%.o: %.c
	$(CC) -g -o $@ -c $< -I mlx

clean:
	rm -rf $(OBJ)

fclean: clean
	rm  -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re 
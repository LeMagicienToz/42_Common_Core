/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:50:25 by muteza            #+#    #+#             */
/*   Updated: 2022/03/17 13:37:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <string.h>

typedef struct s_pospce{
	int	x;
	int	y;
}t_pospce;

typedef struct s_val{
	t_pospce	pos;
	t_pospce	size;
	char		*img;
}t_val;

typedef struct s_data{
	void	*mlx;
	int		width;
	int		height;
	void	*img;
	void	*mlx_win;
}t_data;

typedef struct s_check{
	int			gang;
	char		**map;
	int			nb_col;
	int			move_count;
	t_pospce	p_pos;
	t_data		mlx_mg;
	t_val		exit;
	t_val		grass;
	t_val		wall;
	t_val		collect;
	t_val		player;
}t_check;

typedef struct s_mlxw{
	int	width;
	int	height;
}t_mlxw;

typedef struct s_pce{
	int	p;
	int	c;
	int	e;
}t_pce;

typedef struct s_mapar{
	int	x;
	int	y;
}t_mapar;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*check_all_num(t_pce *mapi, char *str);
char	*ft_strjoin(char *str, char *buf);
char	*get_line(char *str, int ret);
char	*good_line(char *save);
char	*new_buff(char *save);
char	*ft_strchr(char *s, int c);
char	**pos_pcea(char **map, t_check *all);

char	*check_map(char *map, int len, t_pce *mapi);
char	*check_zero_bn(char *str);
char	*check_error_file(char *str);
char	**pos_pce(char **map, t_check *all);
char	**ft_split(char const *s, char c);
char	**last_check_map(char **map, t_mapar *mapou);
char	**parc_wall_top_right(char **map, t_mapar *mapou);
char	*check_un(char *line, t_mapar *mapou);
char	**check_len(char **map, t_mapar *mapou);
char	*check_map_middle(char	*str, int i, t_pce *mapi);
char	*check_first_line(int fd, t_pce *mapi, t_mapar *mapou);
char	*check_pce(char *str, int i, t_pce *mapi);
char	*check_if_folder(int fd, char *str);

int		exit_two(t_check *all);
void	print_walk_left(t_check *all);
void	print_walk_right(t_check *all);
void	print_walk_top(t_check *all);
void	print_walk_down(t_check *all);
void	put_img_two(t_check *all);
void	go_img(t_check *all, char **map);
void	put_img(t_check	*all);
void	ini_pos(t_check *all);
void	check_exit_layer(t_check *all);
void	stock_map(char **map, t_check *all);
void	check_player_layer(t_check *all);
void	check_collect_layer(t_check *all);
void	check_wall_layer(t_check *all);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	check_grass_layer(t_check *all);
void	*ft_calloc(size_t count, size_t size);
void	put_img(t_check	*all);
int		check_col_right(t_check *all);
void	ft_putstr(char *str);
void	move_frame_new_pos(t_check *all, char *path);
char	**check_bn_bouh(char **map, t_mapar *mapou);

int		finish_collect(t_check *all);
int		check_col_down(t_check *all);
int		move_left(t_check *all);
int		move_right(t_check *all);
int		move_down(t_check *all);
int		check_wall_top(t_check *all);
int		move_top(t_check *all);
int		hooks_goos(int keycode, t_check *all);
int		add_pospce(char **map, int x_val, int y_val, t_check *all);
int		add_pospce_two(char **map, int x_val, int y_val, t_check *all);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ini_mlx_zero(t_check *all);
int		put_mlx(int indice);
int		add_pospcea(char **map, int x_val, int y_val, t_check *all);
int		ft_strlen_y(char **map);
int		add_pospce_twoa(char **map, int x_val, int y_val, t_check *all);
void	exit_esc(t_check *all);
int		check_col_left(t_check *all);
int		check_col_top(t_check *all);

size_t	ft_strlen_sl(char *s);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//int		main(int argc, char *argv[]);
#endif
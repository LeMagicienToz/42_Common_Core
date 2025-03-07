/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:46:05 by muteza            #+#    #+#             */
/*   Updated: 2023/06/28 16:37:23 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "./minilibx/mlx.h"
# include "struct.h"

//parsing
void	init_map_string(char *myfile, t_data *data);
void	check_pos(t_data *data);
void	init_map(char *name, t_data *data);
int		check_walls(t_data	*data, int i, int j);
void	check_walls_end(t_data *data);
int		parsing_name(char *str);
int		parsing_ext(char *str);
int		check_codec(char *name);
int		check_file(char *name);
int		check_args(int ac, char **av);
void	get_map(char *myfile, t_data *data);
void	get_info(t_data *data);
int		check_infos(t_data *data);
int		make_all_test(t_data *data, int argc, char **argv);
void	remove_info(t_data *data);
void	init_mlx(t_data *data);
void	convert_rgb_to_hex(t_data *data);
int		get_face(t_data *data, int j, int i);
int		strcmp_check_str(const char check[3], char *str, int i);
int		get_size(t_data *data, char *str, int i);
int		*get_infos_rgb(t_data *data, char *str, int i, char c);
int		check_infos_rgb_f(t_data *d);
int		check_infos_rgb_c(t_data *d);
void	free_map(char **map);
void	save_line_to_del(t_data *data, int j);
void	save_line_to_del_info(t_data *data, int j);
int		just_space_line(t_data *data);
int		is_line_to_del(t_data *data, int j);
void	data_face_save(t_data *data, int i, int j);
void	data_face_restore(t_data *data);
void	del_space_line(t_data *data);
void	error_no_all_info(t_data *data);
int		check_infos_colors(char *str, int i);
int		*ft_atoi_rgb_norm(t_data *data, char *str, int i, int *x);
void	no_leaks(t_data *data);
void	choosing_face(t_data *data);
void	init_var(t_data *data);
int		ini_all_img(t_data *data);
int		check_img_init(t_data *data);

//LES MATH WHALHA
void	recursive_ray(t_data *data);
void	calcul_wall(t_data *data);
void	perform_dda(t_data *data);
int		dda_algo_start(t_data *data);

//mlx
char	*draw_norm_third(t_data *data, int text_x, char *color);
char	*draw_norm_two(t_data *data, int text_x, char *color);
char	*draw_norm(t_data *data, int text_x, char *color);
void	put_map_to_window_first(t_data *data);
void	put_map_to_window(t_data *data);
int		exit_esc(t_data *data);
void	put_img(t_data	*data);
void	make_img(t_data *data);
void	draw_map(t_data *data);
void	norm_mini_map(t_data *data, int i, int j, int y);
void	put_pixel_minimap(t_data *data, int x, int y, int color);

//movement
void	press_e_two(t_data *data, int i, int next_x, int next_y);
void	press_e(t_data *data);
void	ft_movement(t_data *data);
void	rotation_right(t_data *data);
void	move_right(t_data *data);
void	rotation_left(t_data *data);
void	move_left(t_data *data);
void	move_s(t_data *data);
void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_d(t_data *data);
void	move_back(t_data *data);
void	check_all_movement(t_data *data);
int		key_press_code(int key, t_data *data);
int		key_release_code(int key, t_data *data);
void	move_foward(t_data *data);
void	hooks_player(int keycode, t_data *data);

//utils
int		ft_atoi_base(char *str, char *base);
void	*ft_memcpy(void *dst, const void *src, size_t	n);
void	ft_exit(char *str, int i);
int		wich_text_width(t_data *data);
int		wich_text_height(t_data *data);
int		ft_stlren_mapy(t_data *data);
int		ft_stlren_mapx(t_data *data, int i);

void	print_map(t_data *data, char **str);
void	print_good_map(t_data *data, char **str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *b, size_t n);
int		ft_strlen_y(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
int		ft_strncmp(char *check, char c);
int		ft_atoi(char *str);
int		ft_isdigit(int c);

//init
void	init_var(t_data *data);

//draw
void	draw_it(t_data *data);

//minimap
void	ft_mini_map(t_data *data);
void	mini_map_init(t_data *data);

//norm
void	norm_check_infos(void);

#endif
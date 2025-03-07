/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:00:02 by muteza            #+#    #+#             */
/*   Updated: 2023/06/28 16:39:49 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define S_WIDHT 1000
# define S_HEIGHT 800

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYQUIT 17
# define SPEED 0.1
# define FOV 0.2

# define KEY_E 14
# define ROT_L 123
# define ROT_R 124
# define ROTA 2
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

typedef struct s_mlx{
	void	*mlx;
	int		width;
	int		height;
	void	*img;
	int		bpp;
	int		edian;
	int		line_len;
	void	*mlx_win;
	char	*addr;
}t_mlx;

typedef struct s_img
{
	void			*mlx_img;
	int				widht;
	int				height;
	void			*img;
	char			*addr;
	unsigned int	*pixel;
	int				bpp;
	int				line_len;
	int				endian;
	unsigned int	color;
	int				top;
	int				bot;
}	t_img;

typedef struct s_vec{
	double	x;
	double	y;
}t_vec;

typedef struct s_texture{
	double	step;
	double	tex_pos;
	double	height;
	int		text_y;
	int		text_x;
	t_img	nord;
	t_img	sud;
	t_img	est;
	t_img	west;
}t_texture;

typedef struct s_door{
	t_img	text_close;
	t_img	text_open;
}t_door;

typedef struct s_cam{
	t_vec	plane;
	double	cor_x;
}t_cam;

typedef struct s_wall{
	double		pos_wh;
	double		wall_x;
	double		wall_y;
	double		perp_dist;
	int			lineheight;
	int			pix_top;
	int			pix_bot;
}t_wall;

typedef struct s_ray{
	t_vec	dir;
	t_vec	side_dist;
	t_vec	delta_dist;
	int		map_x;
	int		map_y;
	double	cor_x;
}t_ray;

typedef struct s_keys {
	int	w;
	int	a;
	int	s;
	int	d;
	int	rl;
	int	rr;
	int	e;
}	t_keys;

typedef struct s_lim {
	int	left;
	int	right;
	int	top;
	int	bot;
}t_lim;

typedef struct s_minmap{
	int		scale_width;
	int		map_x;
	int		map_y;
	int		map_width;
	int		player_x;
	int		player_y;
	int		map_height;
	int		window_x;
	int		window_y;
	int		pix_pos_x;
	char	**player_print;
	int		pix_pos_y;
	int		size_one_pix;
	int		scale_height;
	t_lim	lim;
	t_img	img;
}t_minmap;

typedef struct s_data{
	char		**map;
	int			error;
	int			pix_x;
	int			i;
	int			j;
	int			minmap_r;
	int			text_height_wall;
	int			text_width_wall;
	int			k;
	char		c;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	char		face;
	int			col;
	int			lin;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			*ff;
	int			*cc;
	int			*del;
	int			hex_ff;
	int			hex_cc;
	char		*rgb_res;
	int			rgb_j;
	int			info_error;
	int			infos;
	int			good;
	int			*face_save;
	int			print_allign;
	int			error_line;
	int			norm_w;
	t_door		door;
	t_minmap	minmap;
	t_texture	text;
	t_wall		wall;
	t_ray		ray;
	t_vec		dir;
	t_vec		player;
	t_cam		cam;
	t_mlx		mlx;
	t_keys		keys;
}t_data;

#endif
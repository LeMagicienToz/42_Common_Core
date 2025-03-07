/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:20:33 by muteza            #+#    #+#             */
/*   Updated: 2022/03/17 13:32:40 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ini_pos(t_check *all)
{
	check_exit_layer(all);
}

void	put_img_two(t_check *all)
{
	if (all->gang == 3)
	{
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/tscott.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->collect.pos.x, all->collect.pos.y);
	}
	if (all->gang == 4)
	{
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/exit.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->exit.pos.x, all->exit.pos.y);
	}
}

int	hooks_goos(int keycode, t_check *all)
{
	if (keycode == 13)
		move_top(all);
	if (keycode == 1)
		move_down(all);
	if (keycode == 2)
		move_right(all);
	if (keycode == 0)
		move_left(all);
	if (keycode == 53)
		exit_esc(all);
	return (0);
}

int	move_top(t_check *all)
{
	if (all->map[all->p_pos.y - 1][all->p_pos.x] != '1' && \
		all->map[all->p_pos.y - 1][all->p_pos.x] != 'E')
		print_walk_top(all);
	if (all->nb_col == 0 && all->map[all->p_pos.y - 1][all->p_pos.x] == 'E')
		exit_esc(all);
	if (all->nb_col != 0 && all->map[all->p_pos.y - 1][all->p_pos.x] == 'E')
		return (0);
	if ((all->map[all->p_pos.y - 1][all->p_pos.x] != '1' && \
	all->map[all->p_pos.y - 1][all->p_pos.x] != 'C') && all->nb_col != 0)
	{
		all->p_pos.y--;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.y -= 64;
		move_frame_new_pos(all, "src/sprite/goose_zk.xpm");
	}
	else if (all->map[all->p_pos.y - 1][all->p_pos.x] != '1' && \
	(all->map[all->p_pos.y - 1][all->p_pos.x] == 'C' || all->nb_col == 0))
		check_col_top(all);
	else
		return (0);
	return (0);
}

void	stock_map(char **map, t_check *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
					all->nb_col++;
			x++;
		}
		x = 0;
		y++;
	}
	all->map = map;
}

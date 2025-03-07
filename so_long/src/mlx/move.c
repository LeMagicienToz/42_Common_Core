/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:56:44 by muteza            #+#    #+#             */
/*   Updated: 2022/03/17 13:45:17 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_frame_new_pos(t_check *all, char *path)
{
	all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
	mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
		all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
	all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			path, &all->mlx_mg.width, &all->mlx_mg.height);
	mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
		all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
}

int	move_down(t_check *all)
{
	if (all->map[all->p_pos.y + 1][all->p_pos.x] != '1' && \
		all->map[all->p_pos.y + 1][all->p_pos.x] != 'E')
		print_walk_down(all);
	if (all->nb_col == 0 && all->map[all->p_pos.y + 1][all->p_pos.x] == 'E')
		exit_esc(all);
	if (all->nb_col != 0 && all->map[all->p_pos.y + 1][all->p_pos.x] == 'E')
		return (0);
	if ((all->map[all->p_pos.y + 1][all->p_pos.x] != '1' && \
	all->map[all->p_pos.y + 1][all->p_pos.x] != 'C') && all->nb_col != 0)
	{
		all->p_pos.y++;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.y += 64;
		move_frame_new_pos(all, "src/sprite/goose_ak.xpm");
	}
	else if (all->map[all->p_pos.y + 1][all->p_pos.x] != '1' && \
	(all->map[all->p_pos.y + 1][all->p_pos.x] == 'C' || all->nb_col == 0))
		check_col_down(all);
	else
		return (0);
	return (0);
}

int	move_right(t_check *all)
{
	if (all->map[all->p_pos.y][all->p_pos.x + 1] != '1' && \
		all->map[all->p_pos.y][all->p_pos.x + 1] != 'E')
		print_walk_right(all);
	if (all->nb_col == 0 && all->map[all->p_pos.y][all->p_pos.x + 1] == 'E')
		exit_esc(all);
	if (all->nb_col != 0 && all->map[all->p_pos.y][all->p_pos.x + 1] == 'E')
		return (0);
	if ((all->map[all->p_pos.y][all->p_pos.x + 1] != '1' && \
	all->map[all->p_pos.y][all->p_pos.x + 1] != 'C') && all->nb_col != 0)
	{
		all->p_pos.x++;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.x += 64;
		move_frame_new_pos(all, "src/sprite/goose_ak.xpm");
	}
	else if (all->map[all->p_pos.y][all->p_pos.x + 1] != '1' && \
	(all->map[all->p_pos.y][all->p_pos.x + 1] == 'C' || all->nb_col == 0))
		check_col_right(all);
	else
		return (0);
	return (0);
}

int	move_left(t_check *all)
{
	if (all->map[all->p_pos.y][all->p_pos.x - 1] != '1' \
		&& all->map[all->p_pos.y][all->p_pos.x - 1] != 'E')
		print_walk_left(all);
	if (all->nb_col == 0 && all->map[all->p_pos.y][all->p_pos.x - 1] == 'E')
		exit_esc(all);
	if (all->nb_col != 0 && all->map[all->p_pos.y][all->p_pos.x - 1] == 'E')
		return (0);
	if ((all->map[all->p_pos.y][all->p_pos.x - 1] != '1' && \
	all->map[all->p_pos.y][all->p_pos.x - 1] != 'C') && all->nb_col != 0)
	{
		all->p_pos.x--;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.x -= 64;
		move_frame_new_pos(all, "src/sprite/goose_ak.xpm");
	}
	else if (all->map[all->p_pos.y][all->p_pos.x - 1] != '1' && \
	(all->map[all->p_pos.y][all->p_pos.x - 1] == 'C' || all->nb_col == 0))
		check_col_left(all);
	else
		return (0);
	return (0);
}

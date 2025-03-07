/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:32:49 by muteza            #+#    #+#             */
/*   Updated: 2022/03/10 18:10:04 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_col_down(t_check *all)
{
	if (all->nb_col == 0)
	{
		all->p_pos.y++;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
		"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
		all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.y += 64;
		move_frame_new_pos(all, "src/sprite/UwU.xpm");
		return (0);
	}
	else
	{
		all->map[all->p_pos.y + 1][all->p_pos.x] = '0';
		all->p_pos.y++;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.y += 64;
		move_frame_new_pos(all, "src/sprite/goose_zk.xpm");
		all->nb_col--;
	}
	return (1);
}

int	check_col_right(t_check *all)
{
	if (all->nb_col == 0)
	{
		all->p_pos.x++;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
		"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
		all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.x += 64;
		move_frame_new_pos(all, "src/sprite/UwU.xpm");
		return (0);
	}
	else
	{
		all->p_pos.x++;
		all->map[all->p_pos.y][all->p_pos.x] = '0';
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.x += 64;
		move_frame_new_pos(all, "src/sprite/goose_zk.xpm");
		all->nb_col--;
	}
	return (1);
}

int	check_col_left(t_check *all)
{
	if (all->nb_col == 0)
	{
	all->p_pos.x--;
	all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
	"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
	all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
	all->player.pos.x -= 64;
		move_frame_new_pos(all, "src/sprite/UwU.xpm");
		return (0);
	}
	else
	{
		all->map[all->p_pos.y][all->p_pos.x - 1] = '0';
		all->p_pos.x--;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.x -= 64;
		move_frame_new_pos(all, "src/sprite/goose_zk.xpm");
		all->nb_col--;
	}
	return (1);
}

int	check_col_top(t_check *all)
{
	if (all->nb_col == 0)
	{
		all->p_pos.y--;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
		"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
	all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
	all->player.pos.y -= 64;
		move_frame_new_pos(all, "src/sprite/UwU.xpm");
		return (0);
	}
	else
	{
		all->map[all->p_pos.y - 1][all->p_pos.x] = '0';
		all->p_pos.y--;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.y -= 64;
		move_frame_new_pos(all, "src/sprite/goose_zk.xpm");
		all->nb_col--;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 06:13:02 by muteza            #+#    #+#             */
/*   Updated: 2022/03/15 13:59:46 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_img(t_check	*all)
{
	if (all->gang == 0)
	{
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->grass.pos.x, all->grass.pos.y);
	}
	if (all->gang == 1)
	{
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/wall.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->wall.pos.x, all->wall.pos.y);
	}
	if (all->gang == 2)
	{
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/goose_ak.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
	}
	put_img_two(all);
}

char	**pos_pcea(char **map, t_check *all)
{
	int			x;
	int			y;
	int			indice;

	indice = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] || map[y][x] == '\n')
		{
			if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == 'E'
			|| map[y][x] == '1' || map[y][x] == '0')
			{
				add_pospcea(map, x, y, all);
				put_img(all);
			}
			x++;
		}
		x = 0;
		y++;
	}
	stock_map(map, all);
	ini_pos(all);
	return (map);
}

int	add_pospcea(char **map, int x_val, int y_val, t_check *all)
{	
	if (map[y_val][x_val] == '0')
	{
		all->grass.pos.x = x_val * 64;
		all->grass.pos.y = y_val * 64;
		all->gang = 0;
	}
	if (map[y_val][x_val] == '1')
	{
		all->wall.pos.x = x_val * 64;
		all->wall.pos.y = y_val * 64;
		all->gang = 1;
	}
	else
		return (add_pospce_twoa(map, x_val, y_val, all));
	return (0);
}

int	add_pospce_twoa(char **map, int x_val, int y_val, t_check *all)
{
	if (map[y_val][x_val] == 'P')
	{
		all->player.pos.x = x_val * 64;
		all->player.pos.y = y_val * 64;
		all->p_pos.x = x_val;
		all->p_pos.y = y_val;
		all->gang = 2;
	}
	if (map[y_val][x_val] == 'C')
	{
		all->collect.pos.x = x_val * 64;
		all->collect.pos.y = y_val * 64;
		all->gang = 3;
	}
	if (map[y_val][x_val] == 'E')
	{
		all->exit.pos.x = x_val * 64;
		all->exit.pos.y = y_val * 64;
		all->gang = 4;
	}
	else
		return (-1);
	return (0);
}

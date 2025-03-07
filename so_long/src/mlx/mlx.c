/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:07:07 by muteza            #+#    #+#             */
/*   Updated: 2022/03/15 13:43:23 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include "minilibx_mms_20200219 4/mlx.h"

char	**pos_pce(char **map, t_check *all)
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
				add_pospce(map, x, y, all);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (map);
}

int	add_pospce(char **map, int x_val, int y_val, t_check *all)
{	
	if (map[y_val][x_val] == '0')
	{
		all->grass.pos.x = x_val;
		all->grass.pos.y = y_val;
		all->gang = 0;
	}
	if (map[y_val][x_val] == '1')
	{
		all->wall.pos.x = x_val;
		all->wall.pos.y = y_val;
		all->gang = 1;
	}
	else
		return (add_pospce_two(map, x_val, y_val, all));
	return (0);
}

int	add_pospce_two(char **map, int x_val, int y_val, t_check *all)
{
	if (map[y_val][x_val] == 'P')
	{
		all->player.pos.x = x_val;
		all->player.pos.y = y_val;
		all->gang = 2;
	}
	if (map[y_val][x_val] == 'C')
	{
		all->nb_col++;
		all->collect.pos.x = x_val;
		all->collect.pos.y = y_val;
		all->gang = 3;
	}
	if (map[y_val][x_val] == 'E')
	{
		all->exit.pos.x = x_val;
		all->exit.pos.y = y_val;
		all->gang = 4;
	}
	return (0);
}

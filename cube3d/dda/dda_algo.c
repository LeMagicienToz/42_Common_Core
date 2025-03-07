/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:18:40 by muteza            #+#    #+#             */
/*   Updated: 2023/06/23 18:40:23 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	calcul_wall(t_data *data)
{
	data->wall.lineheight = (int)(S_HEIGHT / data->wall.perp_dist);
	data->wall.pix_top = -data->wall.lineheight / 2 + S_HEIGHT / 2;
	if (data->wall.pix_top < 0)
		data->wall.pix_top = 0;
	data->wall.pix_bot = data->wall.lineheight / 2 + S_HEIGHT / 2;
	if (data->wall.pix_bot >= S_HEIGHT)
		data->wall.pix_bot = S_HEIGHT - 1;
	if (data->side == 0)
		data->wall.wall_x = data->player.y + data->wall.perp_dist * \
		data->ray.dir.y;
	else
		data->wall.wall_x = data->player.x + data->wall.perp_dist * \
			data->ray.dir.x;
	data->wall.wall_x -= floor(data->wall.wall_x);
	data->text_height_wall = wich_text_height(data);
	data->text_width_wall = wich_text_width(data);
	data->text.text_x = (int)(data->wall.wall_x * (double) \
	data->text_width_wall);
	if (data->side == 0 && data->ray.dir.x > 0)
		data->text.text_x = data->text_width_wall - data->text.text_x - 1;
	if (data->side == 1 && data->ray.dir.x < 0)
		data->text.text_x = data->text_width_wall + data->text.text_x;
	data->text.step = 1.0 * data->text_height_wall / data->wall.lineheight;
	data->text.tex_pos = (data->wall.pix_top - S_HEIGHT / \
	2 + data->wall.lineheight / 2) * data->text.step;
}

void	perform_dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->ray.map_y][data->ray.map_x] == '1' )
			data->hit = 1;
		if (data->map[data->ray.map_y][data->ray.map_x] == 'K')
			data->hit = 2;
		if (data->map[data->ray.map_y][data->ray.map_x] == 'O')
			data->hit = 3;
	}
	if (data->side == 0)
		data->wall.perp_dist = (data->ray.side_dist.x - data->ray.delta_dist.x);
	else
		data->wall.perp_dist = (data->ray.side_dist.y - data->ray.delta_dist.y);
}

void	calcul_step(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->step_x = -1;
		data->ray.side_dist.x = (data->player.x - data->ray.map_x) * \
		data->ray.delta_dist.x;
	}
	else
	{
		data->step_x = 1;
		data->ray.side_dist.x = (data->ray.map_x + 1 - data->player.x) * \
		data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->step_y = -1;
		data->ray.side_dist.y = (data->player.y - data->ray.map_y) * \
		data->ray.delta_dist.y;
	}
	else
	{
		data->step_y = 1;
		data->ray.side_dist.y = (data->ray.map_y + 1 - data->player.y) * \
		data->ray.delta_dist.y;
	}
	perform_dda(data);
}

void	pythagor(t_data *data)
{
	if (data->ray.dir.x == 0)
		data->ray.delta_dist.x = 1e30;
	else
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
	if (data->ray.dir.y == 0)
		data->ray.delta_dist.y = 1e30;
	else
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
	calcul_step(data);
	calcul_wall(data);
	draw_it(data);
}

int	dda_algo_start(t_data *data)
{
	while (data->pix_x != S_WIDHT)
	{
		data->cam.cor_x = 2 * data->pix_x / (double)S_WIDHT - 1;
		data->ray.dir.x = data->dir.x + data->cam.plane.x * data->cam.cor_x;
		data->ray.dir.y = data->dir.y + data->cam.plane.y * data->cam.cor_x;
		data->ray.map_x = (int)data->player.x;
		data->ray.map_y = (int)data->player.y;
		pythagor(data);
		data->pix_x++;
	}
	ft_movement(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
	data->mlx.img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
	data->minmap.img.img, S_WIDHT - data->minmap.scale_width, 0);
	return (0);
}

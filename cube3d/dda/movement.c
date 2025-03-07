/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:31:42 by muteza            #+#    #+#             */
/*   Updated: 2023/06/28 16:56:19 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_a(t_data *data)
{
	if ((data->map[(int)data->player.y] \
	[(int)(data->player.x - data->cam.plane.x * (SPEED + 0.2))]) != '1' && \
	(data->map[(int)data->player.y] \
	[(int)(data->player.x - data->cam.plane.x * (SPEED + 0.2))]) != 'K')
		data->player.x -= data->cam.plane.x * SPEED;
	if ((data->map[(int)(data->player.y - data->cam.plane.y * (SPEED + 0.2))] \
	[(int)data->player.x]) != '1' && \
	(data->map[(int)(data->player.y - data->cam.plane.y * (SPEED + 0.2))] \
	[(int)data->player.x]) != 'K')
		data->player.y -= data->cam.plane.y * SPEED;
	data->pix_x = 0;
}

void	move_d(t_data *data)
{
	if ((data->map[(int)data->player.y][(int) \
			(data->player.x + data->cam.plane.x * (SPEED + 0.2))]) != '1' && \
			(data->map[(int)data->player.y][(int) \
			(data->player.x + data->cam.plane.x * (SPEED + 0.2))]) != 'K')
		data->player.x += data->cam.plane.x * SPEED;
	if ((data->map[(int)(data->player.y + data->cam.plane.y * (SPEED + 0.2))] \
	[(int)data->player.x]) != '1' && \
	(data->map[(int)(data->player.y + data->cam.plane.y * (SPEED + 0.2))] \
	[(int)data->player.x]) != 'K')
		data->player.y += data->cam.plane.y * SPEED;
	data->pix_x = 0;
}

void	norm_mini_map(t_data *data, int i, int j, int y)
{
	if ((i < 0 || i / 20 >= data->minmap.map_width) || \
			(j < 0 || j / 20 >= data->minmap.map_height))
		put_pixel_minimap(data, data->norm_w, y, 0x000000);
	else if (data->map[j / 20][i / 20] == '1')
		put_pixel_minimap(data, data->norm_w, y, data->hex_ff);
	else if (data->map[j / 20][i / 20] == 'K')
		put_pixel_minimap(data, data->norm_w, y, 0xFF00FF);
	else if (data->map[j / 20][i / 20] == 'O')
		put_pixel_minimap(data, data->norm_w, y, 0x008000);
	else if (data->map[j / 20][i / 20] == '0')
		put_pixel_minimap(data, data->norm_w, y, data->hex_cc);
	else if (!ft_strncmp("NSWE", data->map[j / 20][i / 20]))
		put_pixel_minimap(data, data->norm_w, y, data->hex_cc);
}

void	press_e_two(t_data *data, int i, int next_x, int next_y)
{
	next_x = (int)(data->player.x + data->dir.x * (SPEED + i));
	next_y = (int)(data->player.y + data->dir.y * (SPEED + i));
	if (data->map[(int)data->player.y][(int)data->player.x] != 'O')
	{
		if (next_x >= 0 && next_x < data->minmap.map_width && \
		next_y >= 0 && next_y < data->minmap.map_height)
		{
			if ((data->map[(int)data->player.y][(int)(next_x)]) == 'K')
				data->map[(int)data->player.y][(int)(next_x)] = 'O';
			else if ((data->map[(int)(next_y)][(int)data->player.x]) == 'K')
				data->map[(int)(next_y)][(int)data->player.x] = 'O';
			else
			{
				if (data->map[(int)data->player.y][next_x] == 'O')
					data->map[(int)data->player.y][next_x] = 'K';
				if (data->map[next_y][(int)data->player.x] == 'O')
					data->map[next_y][(int)data->player.x] = 'K';
			}
		}
	}
}

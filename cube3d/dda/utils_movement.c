/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:05:10 by muteza            #+#    #+#             */
/*   Updated: 2023/06/28 16:51:39 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_w(t_data *data)
{
	if ((data->map[(int)data->player.y][(int) \
			(data->player.x + data->dir.x * (SPEED + 0.2))]) != '1' && \
			(data->map[(int)data->player.y][(int) \
			(data->player.x + data->dir.x * (SPEED + 0.2))]) != 'K')
		data->player.x += data->dir.x * SPEED;
	if ((data->map[(int)(data->player.y + data->dir.y * (SPEED + 0.2))] \
		[(int)data->player.x]) != '1' && \
		(data->map[(int)(data->player.y + data->dir.y * (SPEED + 0.2))] \
		[(int)data->player.x]) != 'K')
		data->player.y += data->dir.y * SPEED;
	data->pix_x = 0;
}

void	move_s(t_data *data)
{
	if ((data->map[(int)data->player.y][(int) \
			(data->player.x - data->dir.x * (SPEED + 0.2))]) != '1' && \
			(data->map[(int)data->player.y][(int) \
			(data->player.x - data->dir.x * (SPEED + 0.2))]) != 'K')
		data->player.x -= data->dir.x * SPEED;
	if ((data->map[(int)(data->player.y - data->dir.y * (SPEED + 0.2))] \
		[(int)data->player.x]) != '1' && \
		(data->map[(int)(data->player.y - data->dir.y * (SPEED + 0.2))] \
		[(int)data->player.x]) != 'K')
		data->player.y -= data->dir.y * SPEED;
	data->pix_x = 0;
}

void	rotation_left(t_data *data)
{
	double	rotate;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir.x;
	old_plane_x = data->cam.plane.x;
	rotate = 0.05;
	data->dir.x = data->dir.x * cos(rotate) - data->dir.y * sin(rotate);
	data->dir.y = old_dir_x * sin(rotate) + data->dir.y * cos(rotate);
	data->cam.plane.x = data->cam.plane.x * cos(rotate) - data->cam.plane.y \
	* sin(rotate);
	data->cam.plane.y = old_plane_x * sin(rotate) + data->cam.plane.y \
	* cos(rotate);
	data->pix_x = 0;
}

void	press_e(t_data *data)
{
	float	i;
	int		next_x;
	int		next_y;

	i = 0;
	next_x = 0;
	next_y = 0;
	while (i < 3)
	{
		press_e_two(data, i, next_x, next_y);
		i += 0.2;
	}
	data->pix_x = 0;
}

void	rotation_right(t_data *data)
{
	double	rotate;
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir.x;
	old_plane_x = data->cam.plane.x;
	rotate = 0.05;
	data->dir.x = data->dir.x * cos(-rotate) - data->dir.y * sin(-rotate);
	data->dir.y = old_dir_x * sin(-rotate) + data->dir.y * cos(-rotate);
	data->cam.plane.x = data->cam.plane.x * cos(-rotate) - data->cam.plane.y \
	* sin(-rotate);
	data->cam.plane.y = old_plane_x * sin(-rotate) + data->cam.plane.y \
	* cos(-rotate);
	data->pix_x = 0;
}

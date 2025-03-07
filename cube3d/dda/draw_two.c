/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:27:04 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/23 19:40:09 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

char	*draw_norm_third(t_data *data, int text_x, char *color)
{
	if (data->step_x > 0)
	{
		data->text.text_y = (int)data->text.tex_pos & \
		(data->text_height_wall - 1);
		text_x = (int)(data->text.text_x) % data->text_width_wall;
		color = data->text.est.addr + ((int)data->text.text_y * \
		data->text.est.line_len + text_x * (data->text.est.bpp / 8));
	}
	else
	{
		data->text.text_y = (int)data->text.tex_pos & \
		(data->text_height_wall - 1);
		text_x = (int)(data->text.text_x) % data->text_width_wall;
		color = data->text.nord.addr + ((int)data->text.text_y * \
		data->text.nord.line_len + text_x * (data->text.nord.bpp / 8));
	}
	return (color);
}

char	*draw_norm_two(t_data *data, int text_x, char *color)
{
	if (data->step_y < 0)
	{
		data->text.text_y = (int)data->text.tex_pos & \
		(data->text_height_wall - 1);
		text_x = (int)(data->text.text_x) % data->text_width_wall;
		color = data->text.sud.addr + ((int)data->text.text_y * \
		data->text.sud.line_len + text_x * (data->text.sud.bpp / 8));
	}
	else
	{
		data->text.text_y = (int)data->text.tex_pos & \
		(data->text_height_wall - 1);
		text_x = (int)(data->text.text_x) % data->text_width_wall;
		color = data->text.west.addr + ((int)data->text.text_y * \
		data->text.west.line_len + text_x * (data->text.west.bpp / 8));
	}
	return (color);
}

char	*draw_norm(t_data *data, int text_x, char *color)
{
	if (data->hit == 3)
	{
		data->text.text_y = (int)data->text.tex_pos & \
		(data->text_height_wall - 1);
		text_x = (int)(data->text.text_x) % data->text_width_wall;
		color = data->door.text_open.addr + ((int)data->text.text_y * \
		data->door.text_open.line_len + text_x * \
		(data->door.text_open.bpp / 8));
	}
	else if (data->hit == 2)
	{
		data->text.text_y = (int)data->text.tex_pos & \
		(data->text_height_wall - 1);
		text_x = (int)(data->text.text_x) % data->text_width_wall;
		color = data->door.text_close.addr + ((int)data->text.text_y * \
		data->door.text_close.line_len + text_x * \
		(data->door.text_close.bpp / 8));
	}
	return (color);
}

void	recursive_ray(t_data *data)
{
	t_data	lol;

	ft_memcpy(&lol, data, sizeof(t_data));
	lol.hit = 0;
	perform_dda(&lol);
	calcul_wall(&lol);
	draw_it(&lol);
}

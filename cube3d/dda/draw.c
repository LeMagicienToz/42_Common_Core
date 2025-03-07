/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:49:00 by muteza            #+#    #+#             */
/*   Updated: 2023/06/28 16:42:46 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	put_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y >= 0 && y < S_HEIGHT)
	{
		dst = data->mlx.addr + (y * data->mlx.line_len + x * \
		(data->mlx.bpp / 8));
		*(unsigned int *)dst = (unsigned int)color;
	}
}

char	*get_good_text(t_data *data)
{
	char	*color;
	int		text_x;

	text_x = 0;
	color = NULL;
	if (data->hit != 1)
		color = draw_norm(data, text_x, color);
	else if (data->side)
		color = draw_norm_two(data, text_x, color);
	else
		color = draw_norm_third(data, text_x, color);
	return (color);
}

char	*get_good_pixel(t_data *data, int y)
{
	char	*color;
	char	*dst;

	color = get_good_text(data);
	if (y >= 0 && y < S_HEIGHT)
	{
		dst = data->mlx.addr + (y * data->mlx.line_len + data->pix_x * \
				(data->mlx.bpp / 8));
		if (*(unsigned int *)color >> 24 < 128)
			*(unsigned int *)dst = *(unsigned int *)color;
	}
	return (color);
}

void	draw_it(t_data *data)
{
	int				y;

	y = 0;
	while (y < data->wall.pix_top)
	{
		put_pixels(data, data->pix_x, y, data->hex_cc);
		y++;
	}
	if (data->hit == 3)
		recursive_ray(data);
	while (y < data->wall.pix_bot && y < S_HEIGHT)
	{
		data->text.tex_pos += data->text.step ;
		get_good_pixel(data, y);
		y++;
	}
	while (y < S_HEIGHT && y >= data->wall.pix_bot)
	{
		put_pixels(data, data->pix_x, y, data->hex_ff);
		y++;
	}
	data->hit = 0;
}

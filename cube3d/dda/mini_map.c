/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:00:23 by muteza            #+#    #+#             */
/*   Updated: 2023/06/28 16:52:19 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	put_pixel_minimap(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y >= 0 && y <= data->minmap.scale_height)
	{
		dst = data->minmap.img.addr + (y * data->minmap.img.line_len + x * \
		(data->minmap.img.bpp / 8));
		if (color)
			*(unsigned int *)dst = (unsigned int)color;
	}
}

void	mini_map_init(t_data *data)
{
	int		i;

	i = 0;
	data->minmap.scale_height = round((double)(S_HEIGHT / 4.5));
	data->minmap.scale_width = round((double)(S_WIDHT / 4.5));
	data->minmap.img.img = mlx_new_image(data->mlx.mlx, \
	data->minmap.scale_width, data->minmap.scale_height);
	data->minmap.img.addr = mlx_get_data_addr(data->minmap.img.img, \
	&data->minmap.img.bpp, &data->minmap.img.line_len, \
	&data->minmap.img.endian);
	data->minmap.map_width = ft_strlen(data->map[0]);
	data->minmap.map_height = ft_strlen_y(data->map);
}

void	print_player_two(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->minmap.scale_width / 2;
	y = data->minmap.scale_height / 2;
	put_pixel_minimap(data, x, y, 0xFFFF00);
}

void	print_player(t_data *data)
{
	int	i;
	int	j;
	int	y;

	(norm_check_infos(), data->norm_w = 0, y = 0, \
	data->minmap.pix_pos_x = data->player.x \
	* 20, data->minmap.pix_pos_y = data->player.y * 20, \
	j = data->minmap.pix_pos_y - data->minmap.scale_height / 2);
	while (y < data->minmap.scale_height)
	{
		i = data->minmap.pix_pos_x - data->minmap.scale_width / 2;
		while (data->norm_w < data->minmap.scale_width)
		{
			norm_mini_map(data, i, j, y);
			i++;
			data->norm_w++;
		}
		if ((j < 0 || j / 20 >= data->minmap.map_height))
			put_pixel_minimap(data, data->norm_w, y, 0x000000);
		data->norm_w = 0;
		j++;
		y++;
	}
	print_player_two(data);
}

void	ft_mini_map(t_data *data)
{
	mini_map_init(data);
	print_player(data);
}

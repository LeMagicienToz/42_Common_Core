/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:36:20 by muteza            #+#    #+#             */
/*   Updated: 2023/06/23 18:28:21 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ini_all_img_four(t_data *data)
{
	if (!mlx_xpm_file_to_image(data->mlx.mlx, \
	"utils/sprite/door_open_third.xpm", &data->door.text_open.widht, \
	&data->door.text_open.height))
		return (6);
	else
	{
		data->door.text_open.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		"utils/sprite/door_open_third.xpm", &data->door.text_open.widht, \
		&data->door.text_open.height);
		data->door.text_open.addr = mlx_get_data_addr(data->door.text_open.img, \
		&data->door.text_open.bpp, &data->door.text_open.line_len, \
		&data->door.text_open.endian);
	}
	return (0);
}

int	ini_all_img_third(t_data *data)
{
	if (!mlx_xpm_file_to_image(data->mlx.mlx, \
	"utils/sprite/door_close.xpm", &data->door.text_close.widht, \
	&data->door.text_close.height))
		return (5);
	else
	{
		data->door.text_close.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		"utils/sprite/door_close.xpm", &data->door.text_close.widht, \
		&data->door.text_close.height);
		data->door.text_close.addr = mlx_get_data_addr(\
		data->door.text_close.img, &data->door.text_close.bpp, \
		&data->door.text_close.line_len, &data->door.text_close.endian);
	}
	return (ini_all_img_four(data));
}

int	ini_all_img_tow(t_data *data)
{
	if (!mlx_xpm_file_to_image(data->mlx.mlx, \
	data->ea, &data->text.est.widht, \
	&data->text.est.height))
		return (3);
	else
	{
		data->text.est.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		data->ea, &data->text.est.widht, \
		&data->text.est.height);
		data->text.est.addr = mlx_get_data_addr(data->text.est.img, \
		&data->text.est.bpp, &data->text.est.line_len, &data->text.est.endian);
	}
	if (!mlx_xpm_file_to_image(data->mlx.mlx, \
	data->we, &data->text.west.widht, &data->text.west.height))
		return (4);
	else
	{
		data->text.west.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		data->we, &data->text.west.widht, \
		&data->text.west.height);
		data->text.west.addr = mlx_get_data_addr(data->text.west.img, \
		&data->text.west.bpp, &data->text.west.line_len, \
		&data->text.west.endian);
	}
	return (ini_all_img_third(data));
}

int	ini_all_img(t_data *data)
{
	if (!mlx_xpm_file_to_image(data->mlx.mlx, \
	data->no, &data->text.nord.widht, \
	&data->text.nord.height))
		return (1);
	else
	{
		data->text.nord.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		data->no, &data->text.nord.widht, \
		&data->text.nord.height);
		data->text.nord.addr = mlx_get_data_addr(data->text.nord.img, \
		&data->text.nord.bpp, &data->text.nord.line_len, \
		&data->text.nord.endian);
	}
	if (!mlx_xpm_file_to_image(data->mlx.mlx, \
	data->so, &data->text.sud.widht, &data->text.sud.height))
		return (2);
	else
	{
		data->text.sud.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		data->so, &data->text.sud.widht, &data->text.sud.height);
		data->text.sud.addr = mlx_get_data_addr(data->text.sud.img, \
		&data->text.sud.bpp, &data->text.sud.line_len, &data->text.sud.endian);
	}
	return (ini_all_img_tow(data));
}

int	check_img_init(t_data *data)
{
	int	x;

	data->mlx.mlx = mlx_init();
	x = ini_all_img(data);
	if (x == 1)
		return (printf("\n\e[91m[PARSING ERROR : CHECK IMAGE]\n\n[NORD]\e[0m\n\n"), 1);
	if (x == 2)
		return (printf("\n\e[91m[PARSING ERROR : CHECK IMAGE]\n\n[SUD]\e[0m\n\n"), 1);
	if (x == 3)
		return (printf("\n\e[91m[PARSING ERROR : CHECK IMAGE]\n\n[EST]\e[0m\n\n"), 1);
	if (x == 4)
		return (printf("\n\e[91m[PARSING ERROR : CHECK IMAGE]\n\n[WEST]\e[0m\n\n"), 1);
	if (x == 5)
		return (printf("\n\e[91m[PARSING ERROR : CHECK IMAGE]\n\n[DOOR\
 CLOSE]\e[0m\n\n"), 1);
	if (x == 6)
		return (printf("\n\e[91m[PARSING ERROR : CHECK IMAGE]\n\n[DOOR\
 OPEN]\e[0m\n\n"), 1);
	return (0);
}

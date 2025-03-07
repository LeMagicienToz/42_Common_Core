/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:02:29 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/23 19:09:20 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	key_press_code(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit_esc(data);
	if (key == KEY_W)
		data->keys.w = 1;
	if (key == KEY_S)
		data->keys.s = 1;
	if (key == KEY_A)
		data->keys.a = 1;
	if (key == KEY_D)
		data->keys.d = 1;
	if (key == ROT_R)
		data->keys.rr = 1;
	if (key == ROT_L)
		data->keys.rl = 1;
	if (key == KEY_E)
		data->keys.e = 1;
	if (data->keys.e)
	{
		press_e(data);
		ft_mini_map(data);
	}
	return (0);
}

int	key_release_code(int key, t_data *data)
{
	if (key == KEY_W)
		data->keys.w = 0;
	if (key == KEY_S)
		data->keys.s = 0;
	if (key == KEY_A)
		data->keys.a = 0;
	if (key == KEY_D)
		data->keys.d = 0;
	if (key == ROT_R)
		data->keys.rr = 0;
	if (key == ROT_L)
		data->keys.rl = 0;
	if (key == KEY_E)
		data->keys.e = 0;
	return (0);
}

void	ft_movement_norm(t_data *data)
{
	if (data->keys.a)
	{
		move_a(data);
		ft_mini_map(data);
	}
	if (data->keys.d)
	{
		move_d(data);
		ft_mini_map(data);
	}
	if (data->keys.rr)
	{
		rotation_right(data);
		ft_mini_map(data);
	}
	if (data->keys.rl)
	{
		rotation_left(data);
		ft_mini_map(data);
	}
}

void	ft_movement(t_data *data)
{
	if (data->keys.w)
	{
		move_w(data);
		ft_mini_map(data);
	}
	if (data->keys.s)
	{
		move_s(data);
		ft_mini_map(data);
	}
	ft_movement_norm(data);
}

int	exit_esc(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	no_leaks(data);
	exit(0);
	return (0);
}

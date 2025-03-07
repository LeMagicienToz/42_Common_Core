/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:39:58 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/28 17:09:02 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	no_leaks(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->del)
		free(data->del);
	if (data->face_save)
		free(data->face_save);
	if (data->ff)
		free(data->ff);
	if (data->cc)
		free(data->cc);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (make_all_test(&data, argc, argv))
		return (no_leaks(&data), 1);
	init_var(&data);
	data.mlx.img = mlx_new_image(data.mlx.mlx, S_WIDHT, \
			S_HEIGHT);
	data.mlx.addr = mlx_get_data_addr(data.mlx.img, &data.mlx.bpp, \
		&data.mlx.line_len, &data.mlx.edian);
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, S_WIDHT,
			S_HEIGHT, "Cube 3D");
	mini_map_init(&data);
	ft_mini_map(&data);
	mlx_hook(data.mlx.mlx_win, 17, 1L << 0, exit_esc, &data);
	mlx_hook(data.mlx.mlx_win, KEYPRESS, 0, key_press_code, &data);
	mlx_hook(data.mlx.mlx_win, KEYRELEASE, 0, key_release_code, &data);
	mlx_loop_hook(data.mlx.mlx, dda_algo_start, &data);
	mlx_loop(data.mlx.mlx);
}

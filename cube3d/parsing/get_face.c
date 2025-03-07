/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:11:09 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/28 16:53:16 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	get_face(t_data *data, int j, int i)
{
	(norm_check_infos(), j = 0);
	data->face = 3;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
			{
				if (data->face != 3)
					return (data->error_line = j, print_map(data, data->map), \
printf("\n\e[91m[PARSING ERROR : MULTIPLE SPAWN]\n\n(line %d) ==> [%s]\e[0m\n\n", \
data->error_line + 1, data->map[data->error_line]), 1);
				data->face = data->map[j][i];
			}
			i++;
		}
		j++;
	}
	if (data->face == 3)
		return (data->error_line = j, print_map(data, data->map), \
		printf("\n\e[91m[PARSING ERROR : NO SPAWN]\e[0m\n\n"), 1);
	return (printf("\nCHECK SPAWN [\e[92mOK\e[0m]\n"), 0);
}

void	data_face_save(t_data *data, int i, int j)
{
	if (!data->face_save)
		data->face_save = (int *)malloc(sizeof(int) * 2);
	data->face_save[0] = j;
	data->face_save[1] = i;
}

void	data_face_restore(t_data *data)
{
	data->map[data->face_save[0]][data->face_save[1]] = data->face;
}

void	choosing_face(t_data *data)
{
	if (data->face == 'S')
	{
		data->dir.x = 1;
		data->dir.y = 0;
		data->cam.plane.x = 0;
		data->cam.plane.y = -0.30;
	}
	if (data->face == 'E')
	{
		data->dir.x = 0;
		data->dir.y = 1;
		data->cam.plane.x = 0.30;
		data->cam.plane.y = 0;
	}
	if (data->face == 'W')
	{
		data->dir.x = 0;
		data->dir.y = -1;
		data->cam.plane.x = -0.30;
		data->cam.plane.y = 0;
	}
}

void	init_var(t_data *data)
{
	if (data->face == 'N')
	{
		data->dir.x = -1;
		data->dir.y = 0;
		data->cam.plane.x = 0;
		data->cam.plane.y = 0.30;
	}
	choosing_face(data);
	data->player.x = 4;
	data->player.y = 1.1;
	data->pix_x = 0;
	data->hit = 0;
}

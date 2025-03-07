/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:43:34 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/23 20:54:42 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_walls_3000(t_data *data, int i, int j)
{
	while (data->map[j])
	{
		data->error_line = j;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'X' || data->map[j][i] == 'K' \
			|| data->map[j][i] == 'O')
			{
				if (j == 0 || i == 0 || i == ft_strlen(data->map[j]) - 1 \
				|| j == data->col - 1 || i > ft_strlen(data->map[j - 1]))
					return (1);
				if (!ft_strchr("X1OK", data->map[j - 1][i]) || \
				!ft_strchr("X1OK", data->map[j][i + 1]) \
				|| !ft_strchr("X1OK", data->map[j + 1][i]) \
				|| !ft_strchr("X1OK", data->map[j][i - 1]))
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

void	check_walls_cut(t_data *data, int i, int j)
{
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '0')
				data->map[j][i] = 'X';
			i++;
		}
		j++;
	}
}

int	check_walls(t_data	*data, int i, int j)
{
	while (data->map[j])
	{
		data->error_line = j;
		while (data->map[j][i])
		{
			if (!ft_strncmp("NSEW", data->map[j][i]))
			{
				data_face_save(data, i, j);
				data->map[j][i] = 'X';
				check_walls_cut(data, i, j);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (check_walls_3000(data, 0, 0))
		return (print_map(data, data->map), printf("\n\e[91m[PARSING ERROR : \
CHECK WALLS]\n\n(line %d) ==> [%s]\e[0m\n\n", \
data->error_line + 1, data->map[data->error_line]), 1);
	return (data_face_restore(data), check_walls_end(data), \
	printf("\nCHECK WALLS [\e[92mOK\e[0m]\n"), 0);
}

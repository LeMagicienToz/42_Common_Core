/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:34:57 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/21 18:56:20 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	realloc_get_len(t_data *data, int i, int j)
{
	int		len;

	len = 0;
	data->col = 0;
	printf("\nREMOVE BAD LINES :\n");
	while (data->map[j])
	{
		if (!is_line_to_del(data, j))
			len++;
		else
			printf("\n\e[91mDELETED LINE (\e[0m%d\e[91m)\e[0m \
:\n[%s]\e[0m\n", j + 1, data->map[j]);
		while (data->map[j][i])
			i++;
		if (i > data->col)
			data->col = i;
		i = 0;
		j++;
	}
	return (len);
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**realloc_map(t_data *data, int i, int j)
{
	char	**res;
	int		k;

	(norm_check_infos(), k = 0, res = malloc(sizeof(char *) \
	* (data->lin + 1)), res[data->lin] = NULL);
	while (data->map[j])
	{
		if (!is_line_to_del(data, j))
		{
			res[k] = malloc(sizeof(char) * (data->col + 1));
			res[k][data->col] = '\0';
			while (data->col > i)
			{
				if (ft_strlen(data->map[j]) > i)
					res[k][i] = data->map[j][i];
				else
					res[k][i] = ' ';
				i++;
			}
			k++;
			i = 0;
		}
		j++;
	}
	return (free_map(data->map), res);
}

void	set_data_lin(t_data *data)
{
	data->lin = 0;
	while (data->map[data->lin])
		data->lin++;
}

void	remove_info(t_data *data)
{
	int	i;

	i = 0;
	del_space_line(data);
	data->lin = realloc_get_len(data, 0, 0);
	data->map = realloc_map(data, 0, 0);
}

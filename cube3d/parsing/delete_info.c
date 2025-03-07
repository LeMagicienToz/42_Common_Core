/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:43:10 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/21 19:00:06 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	just_space_line(t_data *data)
{
	int	len;
	int	i;
	int	j;
	int	res;

	(norm_check_infos(), j = 0, i = 0, len = 0, res = 0);
	while (data->map[j])
	{
		while (data->map[j][i] == ' ')
		{
			i++;
			len++;
		}
		if (ft_strlen(data->map[j]) == len)
			res++;
		len = 0;
		i = 0;
		j++;
	}
	return (res);
}

void	del_space_line(t_data *data)
{
	int	len;
	int	i;
	int	j;

	j = 0;
	i = 0;
	len = 0;
	while (data->map[j])
	{
		while (data->map[j][i] && data->map[j][i] == ' ')
		{
			i++;
			len++;
		}
		if (ft_strlen(data->map[j]) == len)
			save_line_to_del(data, j);
		len = 0;
		i = 0;
		j++;
	}
}

void	save_line_to_del(t_data *data, int j)
{
	static int	i = 0;

	if (!data->del)
	{
		data->del = (int *)malloc(sizeof(int [7 + just_space_line(data)]));
		data->del[6 + just_space_line(data)] = -1;
	}
	data->del[i++] = j;
}

int	is_line_to_del(t_data *data, int j)
{
	int	i;

	i = 0;
	if (data->del)
	{
		while (data->del[i] != -1)
		{
			if (data->del[i] == j)
				return (1);
			i++;
		}
	}
	return (0);
}

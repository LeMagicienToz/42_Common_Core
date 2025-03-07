/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:56:58 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/28 16:52:50 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	strcmp_check_str(const char check[3], char *str, int i)
{
	int		j;

	j = 0;
	if (check[0] == 'F' || check[0] == 'C')
	{
		while (str[i] && j < 1)
		{
			if (str[i] != check[j])
				return (0);
			i++;
			j++;
		}
	}
	else
	{
		while (str[i] && j < 2)
		{
			if (str[i] != check[j])
				return (0);
			i++;
			j++;
		}
	}
	return (1);
}

int	get_size(t_data *data, char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			while (str[i] && str[i] != ' ')
			{
				len++;
				i++;
			}
			while (str[i])
			{
				if (str[i] != ' ')
					data->info_error = 1;
				i++;
			}
			break ;
		}
		if (ft_strlen(str) > i)
			i++;
	}
	return (len);
}

int	check_infos_colors(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ',' || (str[i] <= '9' && str[i] >= '0') || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	*ft_atoi_rgb_norm(t_data *data, char *str, int i, int *x)
{
	int	*tab;

	(norm_check_infos(), data->rgb_res = NULL, \
	*x = 0, data->rgb_j = 0, tab = NULL);
	while (str[i])
	{
		if (str[i] == ',')
		{
			data->rgb_res[data->rgb_j] = 0;
			if (!tab)
				tab = (int *)malloc(sizeof(int [3]));
			tab[(*x)++] = ft_atoi(data->rgb_res);
			data->rgb_j = 0;
			if (data->rgb_res)
				free(data->rgb_res);
			data->rgb_res = NULL;
		}
		if (!data->rgb_res)
			data->rgb_res = malloc(4);
		if (ft_isdigit(str[i]))
			data->rgb_res[data->rgb_j++] = str[i];
		i++;
	}
	return (tab);
}

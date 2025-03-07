/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:24:36 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/23 17:16:08 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_check_infos(void)
{
}

char	*check_line(t_data *data, char *str, int i)
{
	char	*res;
	int		j;

	j = 0;
	data->infos++;
	if (ft_strlen(str) < i + 3)
		return (NULL);
	while (str[i] != ' ')
		i++;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			res = (char *)malloc(sizeof(char) * (get_size(data, str, i) + 1));
			res[get_size(data, str, i)] = '\0';
			while (str[i] && str[i] != ' ')
				res[j++] = str[i++];
			if (res)
				return (res);
		}
		i++;
	}
	return (NULL);
}

int	set_info(t_data *data, char *str, int i, const char check[3])
{
	int	lol;

	lol = data->infos;
	if (check[0] == 'N' && check[1] == 'O' && !data->no)
		data->no = check_line(data, str, i);
	if (check[0] == 'S' && check[1] == 'O' && !data->so)
		data->so = check_line(data, str, i);
	if (check[0] == 'W' && check[1] == 'E' && !data->we)
		data->we = check_line(data, str, i);
	if (check[0] == 'E' && check[1] == 'A' && !data->ea)
		data->ea = check_line(data, str, i);
	if (check[0] == 'F' && !data->ff)
		data->ff = get_infos_rgb(data, str, i, 'F');
	if (check[0] == 'C' && !data->cc)
		data->cc = get_infos_rgb(data, str, i, 'C');
	if (data->info_error == 1)
		return (1);
	if (lol == data->infos)
		return (1);
	return (0);
}

int	check_infos_split(t_data *data, int x, int j)
{
	const static char	infos[6][3] = {"NO", "SO", "WE", "EA", "F", "C"};
	int					i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != ' ')
		{
			x = 0;
			while (x < 6)
			{
				data->error_line = j;
				if (strcmp_check_str(infos[x], data->map[j], i))
				{
					if (set_info(data, data->map[j], i, infos[x]))
						return (1);
					save_line_to_del(data, j);
					break ;
				}
				x++;
			}
		}
		i++;
	}
	return (0);
}

int	check_infos(t_data *data)
{
	int	x;
	int	j;

	(norm_check_infos(), j = 0, x = 0);
	while (data->map[j])
	{
		if (check_infos_split(data, x, j++))
			return (print_map(data, data->map), printf("\n\e[91m[PARSING \
ERROR : CHECK INFO]\n\n(line %d) ==> [%s]\e[0m\n\n", \
			data->error_line + 1, data->map[data->error_line]), 1);
	}
	if (data->no == NULL || data->so == NULL || data->we == NULL || \
	data->ea == NULL || data->ff == NULL || data->cc == NULL)
		return (error_no_all_info(data), 2);
	return (printf("\nTEXTURES AND COLORS CHECK [\e[92mOK\e[0m]\n"), 0);
}

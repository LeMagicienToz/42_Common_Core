/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:27:00 by muteza            #+#    #+#             */
/*   Updated: 2022/03/15 13:52:34 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_pce(char *str, int i, t_pce *mapi)
{
	if (str[i] == 'P')
		mapi->p++;
	if (str[i] == 'E')
		mapi->e++;
	if (str[i] == 'C')
		mapi->c++;
	return (str);
}

char	*check_un(char *line, t_mapar *mapou)
{
	int	i;
	int	len;

	if (!line)
		return (NULL);
	len = 0;
	i = 0;
	while (line[len] != '\n')
		len++;
	mapou->x = len;
	return (line);
}

char	**last_check_map(char **map, t_mapar *mapou)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (!map)
		return (NULL);
	while (mapou->y > i && map[i][0] == '1')
		i++;
	if (mapou->y != i)
		return (NULL);
	i--;
	while (map[i][k])
	{
		if (map[i][k] != '1')
			return (NULL);
		k++;
	}
	if (mapou->x != k)
		return (NULL);
	map = parc_wall_top_right(map, mapou);
	return (map);
}

char	**parc_wall_top_right(char **map, t_mapar *mapou)
{
	int	k;
	int	i;

	i = 1;
	k = 0;
	while (mapou->x > k)
	{
		if (map[0][k] != '1')
			return (NULL);
		k++;
	}
	k--;
	while (mapou->y > i)
	{
		if (map[i][k] != '1')
			return (NULL);
		i++;
	}
	return (map);
}

char	**check_len(char **map, t_mapar *mapou)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		if (mapou->x != (int)ft_strlen(map[i]))
			return (NULL);
		i++;
	}
	return (map);
}

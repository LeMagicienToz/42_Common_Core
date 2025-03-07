/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:31:42 by muteza            #+#    #+#             */
/*   Updated: 2022/03/15 13:39:57 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_bn_bouh(char **map, t_mapar *mapou)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (mapou->y != i)
		return (NULL);
	else
		return (map);
}

char	*boubou(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (line[i] == '\n')
		return (NULL);
	else
		return (line);
}

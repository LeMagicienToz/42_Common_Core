/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:18:07 by muteza            #+#    #+#             */
/*   Updated: 2023/06/11 10:21:37 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_stlren_mapx(t_data *data, int i)
{
	int	k;

	k = 0;
	while (data->map[i][k])
		k++;
	return (k);
}

int	ft_stlren_mapy(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

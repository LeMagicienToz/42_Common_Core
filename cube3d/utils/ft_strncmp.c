/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 02:36:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/23 20:16:28 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_strncmp(char *check, char c)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (!c || c == '\0')
		return (1);
	while (check[i])
	{
		if (check[i] == c)
			x++;
		i++;
	}
	if (x >= 1)
		return (0);
	return (1);
}

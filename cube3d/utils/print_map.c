/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:31:15 by rperrin           #+#    #+#             */
/*   Updated: 2023/06/23 20:19:35 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	count_line(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
		i++;
	while (i >= 10)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

void	good_line(t_data *data, int j, int g)
{
	int	x;

	x = 0;
	j = j + 1;
	if (g == 1)
	{
		if (data->error_line + 1 == j)
			printf("\e[91m(%d)", j);
		else
			printf("\e[93m(%d)", j);
	}
	else
		printf("(%d)", j);
	while (j >= 10)
	{
		j = j / 10;
		x++;
	}
	x = data->print_allign - x;
	while (x > 0)
	{
		printf(" ");
		x--;
	}
	printf("[");
}

void	print_good_map(t_data *data, char **str)
{
	int		i;
	int		j;

	(norm_check_infos(), i = 0, j = -1, data->print_allign = \
	count_line(data->map));
	if (str == NULL)
	{
		printf("ERROR NO MAP !\n");
		return ;
	}
	printf("\e[92m");
	while (str[++j])
	{
		good_line(data, j, 0);
		while (str[j][i])
		{
			if (str[j][i] == data->face)
				printf("\e[93m%c\e[0m\e[92m", str[j][i++]);
			else
				printf("%c", str[j][i++]);
		}
		printf("]\n");
		i = 0;
	}
	printf("\e[0m");
}

void	print_map(t_data *data, char **str)
{
	int		i;
	int		j;

	(norm_check_infos(), i = 0, j = 0, data->print_allign = \
	count_line(data->map));
	if (str == NULL)
	{
		printf("ERROR NO MAP !\n");
		return ;
	}
	printf("\n");
	while (str[j])
	{
		good_line(data, j, 1);
		while (str[j][i])
			printf("%c", str[j][i++]);
		if (data->error_line == j)
			printf("] [HERE]\e[0m\n");
		else
			printf("]\e[0m\n");
		i = 0;
		j++;
	}
}

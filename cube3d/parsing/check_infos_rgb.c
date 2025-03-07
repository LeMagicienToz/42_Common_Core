/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:09:24 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/19 05:39:50 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	*ft_atoi_rgb(t_data *data, char *str, int i)
{
	int	*tab;
	int	x;

	(norm_check_infos(), data->rgb_res = NULL);
	tab = ft_atoi_rgb_norm(data, str, i, &x);
	data->rgb_res[data->rgb_j] = 0;
	tab[x] = ft_atoi(data->rgb_res);
	if (data->rgb_res)
		free(data->rgb_res);
	if (tab)
		return (tab);
	return (0);
}

int	check_infos_rgb_split(char *str, int i)
{
	int	digit;
	int	separator;

	separator = 0;
	digit = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			digit++;
		if (digit > 3)
			return (1);
		if (str[i] == ',')
		{
			if (digit == 0)
				return (1);
			digit = 0;
			separator++;
		}
		i++;
	}
	if (separator != 2 || digit == 0)
		return (1);
	return (0);
}

int	*get_infos_rgb(t_data *data, char *str, int i, char c)
{
	int	*res;

	data->infos++;
	while (str[i] == ' ')
		i++;
	if (str[i] == c)
		i++;
	if (check_infos_colors(str, i))
		data->info_error = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (check_infos_rgb_split(str, i))
			{
				data->info_error = 1;
				break ;
			}
			res = ft_atoi_rgb(data, str, i);
			if (res)
				return (res);
		}
		i++;
	}
	return (NULL);
}

int	check_infos_rgb_f(t_data *d)
{
	if (d->ff[0] < 0)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(F\
		 = \e[91m%d\e[0m,%d,%d)\n\n", d->ff[0], d->ff[1], d->ff[2]), 1);
	if (d->ff[0] > 255)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(F\
		 = \e[91m%d\e[0m,%d,%d)\n\n", d->ff[0], d->ff[1], d->ff[2]), 1);
	if (d->ff[1] < 0)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(F\
		 = %d,\e[91m%d\e[0m,%d)\n\n", d->ff[0], d->ff[1], d->ff[2]), 1);
	if (d->ff[1] > 255)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(F\
		= %d,\e[91m%d\e[0m,%d)\n\n", d->ff[0], d->ff[1], d->ff[2]), 1);
	if (d->ff[2] < 0)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(F\
		 = %d,%d,\e[91m%d\e[0m)\n\n", d->ff[0], d->ff[1], d->ff[2]), 1);
	if (d->ff[2] > 255)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(F\
		 = %d,%d,\e[91m%d\e[0m)\n\n", d->ff[0], d->ff[1], d->ff[2]), 1);
	return (printf("\nCHECK RGB F [\e[92mOK\e[0m]\n"), 0);
}

int	check_infos_rgb_c(t_data *d)
{
	if (d->cc[0] < 0)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(C\
		 = \e[91m%d\e[0m,%d,%d)\n\n", d->cc[0], d->cc[1], d->cc[2]), 1);
	if (d->cc[0] > 255)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(C\
		 = \e[91m%d\e[0m,%d,%d)\n\n", d->cc[0], d->cc[1], d->cc[2]), 1);
	if (d->cc[1] < 0)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(C\
		 = %d,\e[91m%d\e[0m,%d)\n\n", d->cc[0], d->cc[1], d->cc[2]), 1);
	if (d->cc[1] > 255)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(C\
		 = %d,\e[91m%d\e[0m,%d)\n\n", d->cc[0], d->cc[1], d->cc[2]), 1);
	if (d->cc[2] < 0)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(C\
		 = %d,%d,\e[91m%d\e[0m)\n\n", d->cc[0], d->cc[1], d->cc[2]), 1);
	if (d->cc[2] > 255)
		return (printf("\n\e[91m[PARSING ERROR : BAD RGB COLOR]\n\n\e[0m(C\
		 = %d,%d,\e[91m%d\e[0m)\n\n", d->cc[0], d->cc[1], d->cc[2]), 1);
	return (printf("\nCHECK RGB C [\e[92mOK\e[0m]\n"), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:30:20 by muteza            #+#    #+#             */
/*   Updated: 2022/06/09 15:54:18 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr_double(t_exec *all)
{
	int	i;

	i = 0;
	all->k = 0;
	while (all->str[i])
	{
		if (ft_isdigit(all->str[i], all) == 1 || all->str[i] == ' '
			|| (all->str[i] == '-' && all->str[i + 1] != '-'))
		{
			if (all->str[i] == '-' && all->str[i + 1] == '0')
			{
				all->str[i] = '0';
				all->str[i + 1] = ' ';
			}
			i++;
		}
		else
			return (0);
	}
	if (all->k == 0)
		exit(0);
	if (ft_is_double(all) == 0 || is_int_max(all) == 0)
		return (0);
	return (1);
}

int	is_trillable(t_exec *all)
{
	int	i;
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 0;
	i = 0;
	while (all->tab_a[i] != NULL)
	{
		nb1 = ft_atoi(all->tab_a[i]);
		if (all->tab_a[i + 1] == NULL)
			return (0);
		nb2 = ft_atoi(all->tab_a[i + 1]);
		if (nb1 < nb2)
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_int_max(t_exec *all)
{
	int	i;

	i = 0;
	while (all->nb[i])
	{
		if (ft_strlen(all->nb[i]) > 10)
			return (0);
		ft_atoi(all->nb[i]);
		i++;
	}
	return (1);
}

int	ft_is_double(t_exec *all)
{
	int	i;
	int	k;

	k = 1;
	i = 0;
	all->nb = ft_split(all->str, ' ');
	while (all->nb[i])
	{
		while (all->nb[k])
		{
			if (ft_strlen(all->nb[i]) == ft_strlen(all->nb[k]) && i != k)
			{
				if (ft_strncmp(all->nb[i], all->nb[k],
						ft_strlen(all->nb[i])) == 0)
					return (0);
				k++;
			}
			else
				k++;
		}
			k = 0;
			i++;
	}
	return (1);
}

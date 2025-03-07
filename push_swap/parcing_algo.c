/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:56:51 by muteza            #+#    #+#             */
/*   Updated: 2022/06/10 19:39:42 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parcing_algo(t_exec *all)
{
	int	v;

	v = 1;
	all->i = 0;
	all->k = 0;
	while (all->tab_a[v] && all->i != v)
	{
		if (ft_atoi(all->tab_a[all->i]) > ft_atoi(all->tab_a[v]))
			v++;
		else
		{
			all->i = v;
			v++;
		}
	}
	return (all->i);
}

void	make_a(t_exec *all, int i)
{
	int	k;

	k = 0;
	all->index_topnb = parcing_algo(all);
	sorted_index(all);
	while (all->tab_a[k] && (i != 3 && i != 5))
	{
		if (k == all->index_topnb && all->tab_a[k + 1] != NULL)
		{
			k++;
			rotate_a(all);
		}
		if (all->tab_a[k + 1] == NULL)
			break ;
		k++;
	}
}

void	sorted_index(t_exec *all)
{
	int		i;
	int		k;
	char	*tmp;

	k = 0;
	i = 0;
	while (all->tab_a[i])
		i++;
	while (k < i)
	{
		if ((k + 1 < i) && \
			(ft_atoi(all->tab_a[k]) > ft_atoi(all->tab_a[k + 1])))
		{
			tmp = all->tab_a[k];
			all->tab_a[k] = all->tab_a[k + 1];
			all->tab_a[k + 1] = tmp;
			k = 0;
		}
		else
			k++;
	}
	assigne_sorted_index(all);
}

void	assigne_sorted_index(t_exec *all)
{
	int		i;
	int		k;
	t_list	*tmp;

	i = 0;
	k = 0;
	tmp = all->a;
	while (all->tab_a[i])
		i++;
	while (k < i)
	{
		tmp = all->a;
		while (tmp)
		{
			if (tmp && (ft_atoi(all->tab_a[k]) == tmp->content))
			{
				tmp->sortedindex = i - k - 1;
				k++;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

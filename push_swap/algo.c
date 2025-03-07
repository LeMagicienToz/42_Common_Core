/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:00:47 by muteza            #+#    #+#             */
/*   Updated: 2022/06/10 19:43:37 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_sorted(t_exec *all)
{
	int	i;
	int	j;

	j = 0;
	i = ft_lstsize(all->a);
	while (is_trier(&all) == 1)
	{
		i = ft_lstsize(all->a);
		while (i > 0)
		{
			if ((all->a->sortedindex >> j & 1) == 0)
				rotate_a(all);
			else
				push_b(all);
			i--;
		}
		while (all->b->next != NULL)
			push_a(all);
		push_a(all);
		j++;
	}
}

int	is_trier(t_exec **all)
{
	t_list	*tmp;
	int		i;

	tmp = (*all)->a;
	i = ft_lstsize(tmp);
	while (i > 0 && tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
		i--;
	}
	return (0);
}

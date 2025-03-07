/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:47:17 by muteza            #+#    #+#             */
/*   Updated: 2022/06/11 14:56:09 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_t_to_bot(t_exec *all)
{
	int	x;

	all->tmp_a = all->a;
	x = 0;
	while (all->tmp_a != NULL)
	{
		if (all->tmp_a->sortedindex == all->i)
			break ;
		x++;
		all->tmp_a = all->tmp_a->next;
	}
	return (x);
}

int	find_b_to_top(t_exec *all)
{
	int	i;
	int	x;

	all->tmp_a = all->a;
	i = 0;
	x = 0;
	while (all->tmp_a != NULL)
	{
		all->tmp_a = all->tmp_a->next;
		i++;
	}
	x = find_t_to_bot(all);
	if (x > i / 2)
		return (i - x);
	return (505);
}

int	index_min(t_exec *all)
{
	t_list	*tmp;
	int		index;

	tmp = all->a;
	index = tmp->sortedindex;
	while (tmp->next != NULL)
	{
		if (tmp->sortedindex && tmp->next->sortedindex > index)
			index = tmp->next->sortedindex;
		tmp = tmp->next;
	}
	return (index);
}

void	push_little_two(t_exec *all)
{
	t_list	*tmp;

	tmp = all->a;
	all->min = index_min(all);
	while (tmp->sortedindex != 4)
	{
		rotate_a(all);
		tmp = all->a;
	}
	push_b(all);
}

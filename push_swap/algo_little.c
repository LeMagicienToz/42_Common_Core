/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:46:38 by muteza            #+#    #+#             */
/*   Updated: 2022/06/11 14:51:41 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_third_two(t_exec *all)
{
	if (all->a->sortedindex == 1 && all->a->next->sortedindex == 0)
	{
		reverse_rotate_a(all);
		return (0);
	}
	return (0);
}	

int	algo_third(t_exec *all)
{
	if (all->a->sortedindex == 2 && all->a->next->sortedindex == 0)
	{
		reverse_rotate_a(all);
		swap_a(all);
		return (0);
	}
	if (all->a->sortedindex == 0 && all->a->next->sortedindex == 1)
	{
		swap_a(all);
		reverse_rotate_a(all);
		return (0);
	}
	if (all->a->sortedindex == 1 && all->a->next->sortedindex == 2)
	{
		swap_a(all);
		return (0);
	}
	if (all->a->sortedindex == 0 && all->a->next->sortedindex == 2)
	{
		reverse_rotate_a(all);
		reverse_rotate_a(all);
		return (0);
	}
	return (algo_third_two(all));
}

int	algo_five(t_exec *all)
{
	search_push(all);
	algo_third(all);
	push_a(all);
	push_a(all);
	return (0);
}

int	search_push(t_exec *all)
{
	push_little_two(all);
	push_little(all);
	return (0);
}

void	push_little(t_exec *all)
{
	t_list	*tmp;

	tmp = all->a;
	all->min = index_min(all);
	while (tmp->sortedindex != 3)
	{
		rotate_a(all);
		tmp = all->a;
	}
	push_b(all);
}

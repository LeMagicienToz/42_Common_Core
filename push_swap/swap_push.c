/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:12:14 by muteza            #+#    #+#             */
/*   Updated: 2022/06/10 17:24:58 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_exec *all)
{
	t_list	*tmp_f;

	if (!all->a || all->a->next == NULL)
		exit(0);
	tmp_f = all->a;
	all->a = (t_list *)all->a->next;
	tmp_f->next = all->a->next;
	all->a->next = tmp_f;
	ft_putstr("sa\n");
	return (0);
}

int	swap_b(t_exec *all)
{
	t_list	*tmp_f;

	if (!all->b || all->b->next == NULL)
		exit(0);
	tmp_f = all->b;
	all->b = (t_list *)all->b->next;
	tmp_f->next = all->b->next;
	all->b->next = tmp_f;
	ft_putstr("sb\n");
	return (0);
}

int	push_b(t_exec *all)
{
	t_list	*tmp_f;

	if (!all->a)
		exit(0);
	tmp_f = all->a;
	all->a = all->a->next;
	ft_lstadd_front(&all->b, tmp_f);
	ft_putstr("pb\n");
	all->v++;
	return (0);
}

int	push_a(t_exec *all)
{
	t_list	*tmp_f;

	if (!all->b)
		exit(0);
	tmp_f = all->b;
	all->b = all->b->next;
	ft_lstadd_front(&all->a, tmp_f);
	ft_putstr("pa\n");
	all->v++;
	return (0);
}

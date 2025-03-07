/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:54:15 by muteza            #+#    #+#             */
/*   Updated: 2022/06/10 16:25:20 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_exec *all)
{
	t_list	*tmp_f;
	t_list	*tmp_s;
	t_list	*tmp_l;

	if (!all->a || all->a->next == NULL)
		exit(0);
	tmp_f = all->a;
	tmp_s = tmp_f->next;
	tmp_l = ft_lstlast(all->a);
	tmp_l->next = tmp_f;
	tmp_f->next = NULL;
	all->a = tmp_s;
	ft_putstr("ra\n");
	all->v++;
	return (0);
}

int	rotate_b(t_exec *all)
{
	t_list	*tmp_f;
	t_list	*tmp_s;
	t_list	*tmp_l;

	if (!all->b || all->b->next == NULL)
		exit(0);
	tmp_f = all->b;
	tmp_s = tmp_f->next;
	tmp_l = ft_lstlast(all->b);
	tmp_l->next = tmp_f;
	tmp_f->next = NULL;
	all->b = tmp_s;
	ft_putstr("rb\n");
	return (0);
}

int	reverse_rotate_a(t_exec *all)
{
	t_list	*tmp_f;
	t_list	*tmp_lb;
	t_list	*tmp_l;

	if (!all->a || all->a->next == NULL)
		exit(0);
	tmp_f = all->a;
	tmp_lb = ft_lstlast_m1(all->a);
	tmp_l = ft_lstlast(all->a);
	tmp_l->next = tmp_f;
	tmp_lb->next = NULL;
	all->a = tmp_l;
	ft_putstr("rra\n");
	return (0);
}

int	reverse_rotate_b(t_exec *all)
{
	t_list	*tmp_f;
	t_list	*tmp_lb;
	t_list	*tmp_l;

	if (!all->b || all->b->next == NULL)
		exit(0);
	tmp_f = all->b;
	tmp_lb = ft_lstlast_m1(all->b);
	tmp_l = ft_lstlast(all->b);
	tmp_l->next = tmp_f;
	tmp_lb->next = NULL;
	all->b = tmp_l;
	ft_putstr("rrb\n");
	return (0);
}

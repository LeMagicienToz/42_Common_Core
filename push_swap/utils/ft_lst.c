/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:29:56 by muteza            #+#    #+#             */
/*   Updated: 2022/05/19 16:44:20 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*d;

	if (*alst)
	{
		d = ft_lstlast(*alst);
		d->next = &*new;
	}
	else
		*alst = new;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*d;
// 	t_list	*t;

// 	t = *lst;
// 	while (t)
// 	{
// 		d = t->next;
// 		ft_lstdelone(t, del);
// 		t = d;
// 	}
// 	*lst = NULL;
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	(del)(plst->content);
// 	free(lst);
// }

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }

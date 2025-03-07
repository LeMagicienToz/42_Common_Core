/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:32:25 by muteza            #+#    #+#             */
/*   Updated: 2022/06/07 15:25:43 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstlast_m1(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*t;
// 	t_list	*new;

// 	if (!lst || !del)
// 		return (0);
// 	t = NULL;
// 	while (lst)
// 	{
// 		new = ft_lstnew(f(lst->content));
// 		if (!new)
// 		{
// 			while (t)
// 			{
// 				new = t->next;
// 				(*del)(t->content);
// 				free(t);
// 				t = new;
// 			}
// 		}
// 		lst = lst->next;
// 		ft_lstadd_back(&t, new);
// 	}
// 	return (t);
// }

t_list	*ft_lstnew(int content)
{
	t_list	*d;

	d = (t_list *)malloc(sizeof(t_list));
	if (!d)
		return (NULL);
	d->next = NULL;
	d->content = content;
	return (d);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

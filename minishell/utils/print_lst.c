/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:52 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 22:29:48 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_lexer(t_lexer	*lexer)
{
	t_lexer	*tmp;

	tmp = lexer;
	printf("[PRINT-LEXER]\n");
	while (tmp)
	{
		printf("[%d] - (%s)\n", tmp->type, tmp->content);
		tmp = tmp->next;
	}
	printf("[PRINT-LEXER]\n");
}

void	print_lst(t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	printf("[PRINT-LST]\n");
	while (tmp)
	{
		printf("[%d] - (%s)\n", tmp->index, tmp->content);
		tmp = tmp->next;
	}
	printf("[PRINT-LST]\n");
}

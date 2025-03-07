/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:34:33 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 23:44:31 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*export_quote_norm(t_lexer **lexer, t_data *data, \
char *res, int x)
{
	char	*tmp;
	t_lexer	*lex;

	tmp = NULL;
	lex = (*lexer);
	while (lex && lex->type != x)
	{
		if (lex->type == DOLLAR && lex->next->type == TEXT)
			res = fill_dollar(&lex, data, res);
		else if (res && lex->content && lex->type != x)
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, lex->content);
			free(tmp);
		}
		else if (lex->type != x)
			res = ft_strdup(lex->content);
		if (lex)
			lex = lex->next;
	}
	(*lexer) = lex;
	return (res);
}

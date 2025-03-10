/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hyphen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:45:40 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 12:18:50 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*fill_hyphen(t_lexer **lex, t_data *data, char *res)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = (*lex);
	tmp = tmp->next;
	tmp = tmp->next;
	while (tmp->content[i])
	{
		if (tmp->content[i++] == 'n')
			data->hyphen = 1;
		else
		{
			data->hyphen = 0;
			break ;
		}
	}
	if (tmp->next && tmp->next->type == HYPHEN && data->stopn != 1)
	{
		(*lex) = (*lex)->prev;
		data->stopn = 1;
		return (res);
	}
	fill_hyphen_norm(tmp, data);
	return (fill_hyphen_normed(lex, data, res));
}

void	fill_hyphen_norm(t_lexer *tmp, t_data *data)
{
	if (!tmp->next || tmp->next->type == SPACE)
	{
		if (data->hyphen == 1 && data->n == -1 && data->stopn == 0)
		{
			data->n = 1;
		}
		else if (data->hyphen == 0 && data->n == -1)
		{
			data->stopn = 1;
		}
		else if (data->hyphen == 0)
			data->stopn = 1;
	}
}

char	*fill_hyphen_join(t_lexer **lex, char *res)
{
	char	*noleaks;
	t_lexer	*tmp;

	tmp = (*lex);
	noleaks = ft_strdup(res);
	free(res);
	res = ft_strjoin(noleaks, tmp->content);
	free(noleaks);
	tmp = tmp->next;
	noleaks = ft_strdup(res);
	free(res);
	res = ft_strjoin(noleaks, tmp->content);
	free(noleaks);
	(*lex) = tmp;
	return (res);
}

char	*fill_hyphen_normed(t_lexer **lex, t_data *data, char *res)
{
	t_lexer	*tmp;

	tmp = (*lex);
	if (data->stopn == 1 || data->hyphen != 1)
	{
		res = fill_hyphen_join(lex, res);
		data->stopn = 1;
	}
	else
	{
		tmp = tmp->next->next;
		(*lex) = tmp;
	}
	return (res);
}

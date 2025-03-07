/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_third.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:32:56 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 16:59:00 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	get_parsed_export_two_normed(t_data *data, t_exp *exp)
{
	if (exp->res)
	{
		create_token(data, &exp->lst, exp->res);
		data->maxindex++;
		free(exp->res);
		exp->res = NULL;
	}
}

void	get_parsed_export_one_normed(t_data *data, t_exp *exp)
{
	if (exp->tmp->prev && exp->tmp->prev->\
	content[ft_strlen(exp->tmp->prev->content) - 1] == '=')
		;
	else if (exp->res)
	{
		create_token(data, &exp->lst, exp->res);
		free(exp->res);
		exp->res = NULL;
		data->maxindex++;
	}
	exp->res = fill_quote_export(&exp->tmp, data, exp->res);
	create_token(data, &exp->lst, exp->res);
	data->maxindex++;
	free(exp->res);
	exp->res = NULL;
}

void	get_parsed_export_normed(t_data *data, t_exp *exp)
{
	if (exp->tmp->type == DOLLAR && exp->tmp->next->type == TEXT)
		exp->res = fill_dollar(&exp->tmp, data, exp->res);
	else if ((exp->tmp->type == DBQUOTE || exp->tmp->type == QUOTE) && \
	exp->tmp->next)
		get_parsed_export_one_normed(data, exp);
	else if (exp->tmp->type == SPACE)
		get_parsed_export_two_normed(data, exp);
	else if (exp->res && exp->tmp->content && exp->tmp->type != QUOTE && \
	exp->tmp->type != DBQUOTE)
	{
		exp->join = ft_strdup(exp->res);
		free(exp->res);
		exp->res = ft_strjoin(exp->join, exp->tmp->content);
		free(exp->join);
	}
	else if (exp->tmp->type != DBQUOTE || exp->tmp->type != QUOTE)
		exp->res = ft_strdup(exp->tmp->content);
}

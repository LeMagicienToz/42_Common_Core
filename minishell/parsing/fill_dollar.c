/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:32:42 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 22:41:40 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_dollar_token(char *str, t_data *data)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	data->dollartoken = NULL;
	while (str[i])
	{
		if (!ft_isalnum(str[i++]))
		{
			res = ft_substr(str, 0, i - 1);
			data->dollartoken = ft_substr(str, i - 1, ft_strlen(str));
		}
	}
	if (!res)
		res = ft_strdup(str);
	return (res);
}

char	*fill_dollar_normdeouf(t_data *data, char *leaks, char *res)
{
	leaks = ft_strdup(res);
	free(res);
	res = ft_strjoin(leaks, data->dollartoken);
	free(data->dollartoken);
	free(leaks);
	return (res);
}

char	*fill_dollar_normed_norm(char *res, \
char *leaks, char *lol, t_data *data)
{
	char	*tmp;

	tmp = NULL;
	if (!res && leaks)
	{
		res = ft_strdup(leaks);
		free(leaks);
	}
	else if (leaks)
	{
		free(leaks);
		tmp = ft_strdup(res);
		free(res);
		leaks = get_env(data, lol);
		res = ft_strjoin(tmp, leaks);
		free(leaks);
		free(tmp);
	}
	return (res);
}

char	*fill_dollar_normed(t_lexer **lexer, t_data *data, char *res)
{
	t_lexer	*lex;
	char	*lol;
	char	*leaks;

	leaks = NULL;
	lex = (*lexer);
	lex = lex->next;
	lol = ft_dollar_token(lex->content, data);
	leaks = get_env(data, lol);
	res = fill_dollar_normed_norm(res, leaks, lol, data);
	free(lol);
	if (data->dollartoken)
		res = fill_dollar_normdeouf(data, leaks, res);
	(*lexer) = lex;
	return (res);
}

char	*fill_dollar_norm(t_lexer **lexer, t_data *data, char *res, char *tmp)
{
	t_lexer	*lex;
	char	*leaks;

	lex = (*lexer);
	lex = lex->next;
	if (!res)
	{
		leaks = ft_itoa(data->status);
		res = leaks;
		free(leaks);
	}
	else
	{
		tmp = ft_strdup(res);
		free(res);
		leaks = ft_itoa(data->status);
		res = ft_strjoin(tmp, leaks);
		free(leaks);
		free(tmp);
	}
	(*lexer) = lex;
	return (res);
}

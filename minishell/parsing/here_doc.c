/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:16 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/23 00:12:30 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signal_handler_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		g_errors.heredoc_stop = 1;
		g_errors.heredocstatus = 1;
		exit(0);
	}
}

int	check_here_doc(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == INCODE && str[i + 1] == INCODE)
		{
			i = i + 2;
			while (str[i] && str[i] != PIPECODE)
			{
				if (check_token(str[i++], (char)0) == TEXT)
					return (1);
			}
			data->status = 403;
			return (2);
		}
		i++;
	}
	return (0);
}

char	*here_doc_normed(t_data *data, char *tmp, char *read, char *end)
{
	while (1)
	{
		if (read)
			free(read);
		read = readline("> ");
		if (!read)
		{
			g_errors.heredoc_stop = 1;
			if (data->heredocres)
				free(data->heredocres);
			break ;
		}
		if (!ft_strcmp(read, end))
			break ;
		if (!data->heredocres)
			data->heredocres = ft_strdup(read);
		else
		{
			tmp = ft_strdup(data->heredocres);
			free(data->heredocres);
			data->heredocres = ft_strjoin(tmp, read);
			free(tmp);
		}
	}
	return (data->heredocres);
}

void	here_doc_norm(t_data *data, char *tmp, char *read)
{
	g_errors.heredoc_signal = 1;
	g_errors.heredoc_stop = 0;
	g_errors.heredocstatus = 0;
	tmp = ft_itoa(data->heredocnb);
	read = ft_strjoin("heredoc", tmp);
	data->in = open(read, O_CREAT | O_RDWR | O_TRUNC, 0600);
	free(read);
	free(tmp);
	tmp = NULL;
	read = NULL;
}

void	here_doc(char *end, t_data *data)
{
	char	*tmp;
	char	*read;
	int		vv;
	int		id;

	read = NULL;
	tmp = NULL;
	data->heredocres = NULL;
	id = fork();
	here_doc_norm(data, tmp, read);
	if (id == 0)
	{
		signal(SIGINT, signal_handler_heredoc);
		signal(SIGQUIT, SIG_IGN);
		here_doc_normed(data, tmp, read, end);
		if (g_errors.heredoc_stop == 1)
			exit(1);
		if (data->heredocres)
			(write(data->in, data->heredocres, \
			ft_strlen(data->heredocres)), free(data->heredocres));
		exit (1);
	}
	waitpid(id, &vv, 0);
	g_errors.heredoc_signal = 0;
	data->status = g_errors.heredocstatus;
}

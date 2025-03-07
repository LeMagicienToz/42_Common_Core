/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/23 00:18:54 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	tiensmax(t_lst *lst, t_data *data)
{
	t_lst	*tmp;
	int		last;

	last = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == last + 1)
			last = tmp->index;
		tmp = tmp->next;
	}
	check_pipe(lst, data);
}

void	main_norm(t_lexer **lexer, t_lst **lst, t_data *data)
{
	lexer = NULL;
	lst = NULL;
	data->export = NULL;
	data->env = NULL;
	g_errors.heredoc_signal = 0;
	init_exp(data);
	echo_control_seq(0);
	make_first_envi(data);
}

int	main(__attribute__((unused))int argc, \
__attribute__((unused))char **argv,	char **envp)
{
	t_data	data;
	t_lst	*lst;
	t_lexer	*lexer;

	if (init_data(&data, envp) == 1)
		return (0);
	main_norm(&lexer, &lst, &data);
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
		if (data.input == NULL)
			data.input = readline("8-----> ");
		if (data.input == NULL)
			return (0);
		remake_envi(&data);
		add_history(data.input);
		data.check = check_lexer_error(data.input, &data);
		if (data.check == 0)
			launch(&data, lst, lexer);
		else
			get_error(&data);
		if (g_errors.heredocstatus == 130 || g_errors.heredocstatus == 1)
			data.status = g_errors.heredocstatus;
	}
}

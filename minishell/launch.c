/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:31:58 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 22:23:55 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	check_lst_launch(t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		while (tmp->content[i] == ' ')
			i++;
		if ((int)ft_strlen(tmp->content) == i)
			return (0);
		i = 0;
		tmp = tmp->next;
	}
	return (1);
}

void	launch(t_data *data, t_lst *lst, t_lexer *lexer)
{
	lexer = create_lexer(lexer, data->input);
	lst = get_parsed(lexer, data);
	data->lexer = lexer;
	if (lst && check_lst_launch(lst))
	{
		tiensmax(lst, data);
		free_all(data, &lexer, &lst);
	}
	else if (data->input)
	{
		free_all(data, &lexer, &lst);
		data->status = 0;
		if (lst)
			free_lst(&lst);
		free_lex(&lexer);
		data->in = 0;
		free(data->input);
		data->input = NULL;
	}
}

void	get_error(t_data *data)
{
	if (data->status == 404)
		printf("Erreur: Impossible de lancer Minishell sans environnement\n");
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
}

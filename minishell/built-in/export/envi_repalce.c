/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi_repalce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:36:39 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 23:43:34 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	get_i(t_lst *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		i++;
		if (tmp)
			tmp = tmp->next;
	}
	return (i);
}

int	make_first_envi(t_data *data)
{
	int		i;
	t_lst	*tmp;

	if (!data->env)
		return (0);
	tmp = data->env;
	i = get_i(tmp) / 2;
	tmp = data->env;
	data->envi = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp->next->next)
	{
		data->envi[i] = ft_strjoin(tmp->content, tmp->next->content);
		i++;
		tmp = tmp->next->next;
	}
	data->envi[i] = ft_strjoin(tmp->content, tmp->next->content);
	data->envi[i + 1] = NULL;
	return (0);
}

void	remake_envi(t_data *data)
{
	if (data->envi)
		free_data_str(data->envi);
	make_first_envi(data);
}

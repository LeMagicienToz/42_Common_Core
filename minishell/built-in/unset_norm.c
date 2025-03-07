/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:42:09 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 23:32:23 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_unset_patch_norm(t_data *data, int i, char	*join, char	*save)
{
	char	*leaks;

	if (save == NULL)
	{
		leaks = ft_strjoin(" ", data->str[i]);
		save = ft_strjoin(data->str[i - 1], leaks);
	}
	else
	{
		join = ft_strdup(save);
		free(save);
		leaks = ft_strjoin(" ", data->str[i]);
		save = ft_strjoin(join, leaks);
		free(join);
	}
	free (leaks);
	return (save);
}

char	*ft_unset_patch(t_data *data)
{
	int		i;
	char	*join;
	char	*save;

	save = NULL;
	join = NULL;
	i = 2;
	while (data->str && data->str[i])
		save = ft_unset_patch_norm(data, i++, join, save);
	if (save == NULL)
		save = ft_strdup(data->str[1]);
	return (save);
}

char	**init_unset_norm(t_data *data, char **lol)
{
	char	*str;

	str = NULL;
	if (check_nb_str(data) > 1)
	{
		str = ft_unset_patch(data);
		lol = ft_split(str, ' ');
		free(str);
	}
	else
		lol = data->str;
	return (lol);
}

void	free_lst_unset(t_lst **lst)
{
	t_lst	*tmp;

	tmp = (*lst);
	free(tmp->next->content);
	free(tmp->next);
	free(tmp->content);
	free(tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:24 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/23 00:10:57 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_cd_normeeeeeed(t_data *data, char *str)
{
	int		i;
	char	cwd[1025];

	i = 0;
	i = chdir(data->str[1]);
	if (!data->save_builtin)
		data->save_builtin = getcwd(NULL, sizeof(cwd));
	else
	{
		free(data->save_builtin);
		data->save_builtin = getcwd(NULL, sizeof(cwd));
	}
	if (i == -1)
	{
		if (str)
			free (str);
		return (erreur_status(1, "ERROR: Something \
		goes wrong with cd ARGS", data, 0), 0);
	}
	return (0);
}

void	ft_cd_normed_norm(t_data *data)
{
	char	*tmp;

	tmp = go_to_home(data);
	ft_cd_normed(data, tmp);
	free (tmp);
}

void	ft_cd_gaming(t_data *data)
{
	char	*leaks;

	leaks = ft_strdup(data->str[1]);
	free(data->str[1]);
	data->str[1] = ft_cd_token(leaks, data);
	free(leaks);
}

int	ft_cd_normlol(t_data *data)
{
	if (data->maxindex != 0)
		return (1);
	if (data->str[1] == 0)
	{
		ft_cd_normed_norm(data);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:22:26 by muteza            #+#    #+#             */
/*   Updated: 2023/02/23 00:09:49 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*go_to_home(t_data *data)
{
	t_lst	*tmp;
	char	*str;

	tmp = data->env;
	while (tmp)
	{
		if (tmp->next && ft_strcmp(tmp->content, "HOME=") == 0)
		{
			tmp = tmp->next;
			str = ft_strdup(tmp->content);
			return (str);
		}
		tmp = tmp->next;
	}
	erreur_status(1, "ERROR: Can't find HOME in PATH", data, 0);
	return (NULL);
}

void	ft_cd_normed(t_data *data, char *tmp)
{
	if (!tmp)
		erreur_status(1, "ERROR: HOME is not set", data, 0);
	else
		chdir(tmp);
}

char	*ft_cd_token(char *str, t_data *data)
{
	int		i;
	char	*save;
	char	*join;
	char	*res;

	res = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i++] == '~')
		{
			res = ft_substr(str, 0, i - 1);
			join = go_to_home(data);
			save = ft_strjoin(res, join);
			free(join);
			free(res);
			join = ft_substr(str, i, ft_strlen(str));
			res = ft_strjoin(save, join);
			free(save);
			free(join);
		}
	}
	if (!res)
		res = ft_strdup(str);
	return (res);
}

int	check_nb_str(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i] != NULL)
		i++;
	return (i);
}

int	ft_cd(t_data *data)
{
	char	cwd[1025];
	char	*str;

	str = NULL;
	if (check_nb_str(data) == 3)
		return (erreur_status(1, "ERROR: Too many arguments", data, 0), 0);
	if (!getcwd(cwd, sizeof(cwd)))
		return (chdir(data->str[1]));
	str = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (ft_cd_normlol(data))
	{
		if (str)
			free(str);
		return (0);
	}
	else
		ft_cd_gaming(data);
	ft_cd_normeeeeeed(data, str);
	if (str)
		free(str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:11:31 by muteza            #+#    #+#             */
/*   Updated: 2022/04/12 17:03:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_access_first(t_exec *all, char **str, char *path)
{
	int		i;
	char	**f_arg;
	int		ret;
	char	*good_path;

	i = 0;
	good_path = NULL;
	f_arg = ft_split(path, ':');
	all->f_com = ft_split(str[2], ' ');
	while (f_arg[i])
	{
		f_arg[i] = ft_strjoin(f_arg[i], "/");
		f_arg[i] = ft_strjoin(f_arg[i], all->f_com[0]);
		ret = access(f_arg[i], X_OK);
		if (ret < 0)
			i++;
		else
			break ;
	}
	if (ret < 0)
		exit(write(1, "ERROR\nCan not execute the first command", 39));
	good_path = ft_strjoin(good_path, f_arg[i]);
	free_path(f_arg, path);
	return (good_path);
}

char	*check_access_second(t_exec *all, char **str, char *path)
{
	int		i;
	char	**f_arg;
	int		ret;
	char	*good_path;

	i = 0;
	good_path = NULL;
	f_arg = ft_split(path, ':');
	all->s_com = ft_split(str[3], ' ');
	while (f_arg[i])
	{
		f_arg[i] = ft_strjoin(f_arg[i], "/");
		f_arg[i] = ft_strjoin(f_arg[i], all->s_com[0]);
		ret = access(f_arg[i], X_OK);
		if (ret < 0)
			i++;
		else
			break ;
	}
	if (ret < 0)
		exit(write(1, "ERROR\nCan not execute the second command", 40));
	good_path = ft_strjoin(good_path, f_arg[i]);
	free_path(f_arg, path);
	return (good_path);
}

void	free_path(char **str, char *path)
{
	int	i;

	free(path);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

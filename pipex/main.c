/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:29:14 by muteza            #+#    #+#             */
/*   Updated: 2022/04/14 17:48:41 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

int	parcing_arguments(int nb_arg, char **str, char **env)
{
	t_exec	all;

	if (nb_arg != 5)
	{
		ft_putstr("ERROR\nProblem with arguments");
		return (0);
	}
	else
	{
		check_files(&all, str);
		all.path_first = check_first_command(&all, str, env);
		all.path_second = check_second_command(&all, str, env);
		fork_ini(&all);
	}
	return (0);
}

char	*check_first_command(t_exec *all, char **str, char **env)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
	{
		if (env[i + 1] == NULL)
			exit(write(1, "ERROR\nCan't find PATH for arguments\n", 36));
		if (!env[++i])
			break ;
	}
	if (ft_strncmp(env[i], "PATH=", 5) == 0)
	{
		path = ft_strjoin(path, &env[i][5]);
		return (check_access_first(all, str, path));
	}
	else
	{
		ft_putstr("ERROR\nCan't find PATH for arguments\n");
		exit(0);
	}
	return (NULL);
}

char	*check_second_command(t_exec *all, char **str, char **env)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
	{
		if (!env[++i])
			break ;
	}
	path = ft_strjoin(path, &env[i][5]);
	return (check_access_second(all, str, path));
}

void	check_files(t_exec *all, char **str)
{
	all->f1 = open(str[1], O_RDWR);
	if (all->f1 < 0)
	{
		ft_putstr("ERROR\nCan't open first file\n");
		exit(0);
	}
	all->f3 = unlink(str[4]);
	all->f3 = open (str[4], O_RDWR);
	if (all->f3 < 0)
	{
		all->f3 = open (str[4], O_CREAT | O_RDWR);
	}
}

int	main(int argc, char **argv, char **env)
{
	if (env[0] == NULL)
	{
		ft_putstr("Error\nPas d'environement !!");
		exit(0);
	}
	parcing_arguments(argc, argv, env);
}

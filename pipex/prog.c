/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:20:58 by muteza            #+#    #+#             */
/*   Updated: 2022/04/13 18:42:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_ini(t_exec *all)
{
	pipe(all->fd);
	all->id = fork();
	redirection_exec(all);
}

int	redirection_exec(t_exec *all)
{
	if (all->id == 0)
	{
		close(all->fd[0]);
		dup2(all->f1, 0);
		close(all->f1);
		dup2(all->fd[1], 1);
		close(all->fd[1]);
		execve(all->path_first, all->f_com, 0);
	}
	else if (all->id != 0)
	{
		wait(NULL);
		close (all->fd[1]);
		dup2(all->fd[0], 0);
		close (all->fd[0]);
		dup2(all->f3, 1);
		execve(all->path_second, all->s_com, 0);
	}
	return (0);
}

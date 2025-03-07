/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:53:37 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 15:30:57 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_pwd(t_data *data, t_lst *lst)
{
	char	cwd[1025];
	char	*str;
	int		k;

	k = 0;
	if (!getcwd(cwd, sizeof(cwd)))
	{
		k = 1;
		str = ft_strdup(data->save_builtin);
	}
	else
		str = getcwd(cwd, sizeof(cwd));
	if (str == NULL)
		str = data->save_builtin;
	if (lst->next)
	{
		write(data->fd[1], str, ft_strlen(str));
		write(data->fd[1], "\n", 1);
	}
	else
		printf("%s\n", str);
	if (k == 1)
		free(str);
}

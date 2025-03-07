/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_com_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:05:28 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 18:27:51 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	put_lst_in_tab_normed(t_data *data, t_lst *tmp, char *noleaks)
{
	data->str = free_data_str(data->str);
	data->str = malloc(sizeof(char *) * 3);
	data->str[0] = ft_strdup(noleaks);
	data->str[1] = patch_args_simple(ft_substr(tmp->content, \
	(int)ft_strlen(noleaks) + 1, \
	ft_strlen(tmp->content)));
	data->str[2] = NULL;
	free(noleaks);
}

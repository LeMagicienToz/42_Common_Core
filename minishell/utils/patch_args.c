/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:12:32 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 22:29:26 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**patch_args(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str && str[j])
	{
		while (str[j][i])
		{
			if (str[j][i] == (char)1)
				str[j][i] = ' ';
			i++;
		}
		i = 0;
		j++;
	}
	return (str);
}

char	*patch_args_simple(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)1)
			str[i] = SPACECODE;
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:19:43 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 23:02:43 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit_norm(t_data *data)
{
	if (!data->str[1])
	{
		free_data(data);
		exit (0);
	}
}

int	ft_exit(t_data *data)
{
	ft_exit_norm(data);
	if (data->str[1] && data->maxindex == 0)
	{
		if (ft_is_numeric(data->str[1]) == 0)
		{
			data->status = ft_atoi(data->str[1]);
			if (data->status > 256)
				data->status %= 256;
		}		
		else
		{
			free_data(data);
			erreur_status(255, "ERROR: exit: numeric argument required", \
			data, 1);
		}
	}
	if (data->str[2] && data->maxindex == 0)
		return (erreur_status(1, "Error: exit: \
		too many arguments", data, 0), 0);
	if (data->maxindex == 0)
		exit(data->status);
	if (data)
		free_data(data);
	return (0);
}

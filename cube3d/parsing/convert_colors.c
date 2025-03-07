/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:29:29 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/28 16:41:35 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	norm_hex(void)
{
}

char	*convert_tab_to_char(char base[16], int *tab)
{
	int		i;
	int		j;
	char	*hex;

	(norm_hex(), hex = malloc(sizeof(char) * 7), \
	hex[6] = '\0', i = 0, j = 0);
	while (i < 3)
	{
		if (tab[i] == 0)
			(norm_hex(), hex[j++] = '0', hex[j++] = '0', i++);
		else
		{
			hex[j++] = base[tab[i] / 16];
			if (tab[i] % 16)
				hex[j++] = base[tab[i++] % 16];
			else
				(norm_hex(), hex[j++] = '0', i++);
		}
	}
	return (hex);
}

void	convert_rgb_to_hex(t_data *data)
{
	data->hex_ff = ft_atoi_base(convert_tab_to_char("0123456789ABCDEF", \
	data->ff), "0123456789ABCDEF");
	free(data->ff);
	data->ff = NULL;
	data->hex_cc = ft_atoi_base(convert_tab_to_char("0123456789ABCDEF", \
	data->cc), "0123456789ABCDEF");
	free(data->cc);
	data->cc = NULL;
}

void	error_no_all_info(t_data *data)
{
	if (!data->no)
		printf("\n\e[91m[PARSING ERROR : NO ALL INFO]\n\n(NO = NULL)\e[0m\n\n");
	if (!data->so)
		printf("\n\e[91m[PARSING ERROR : NO ALL INFO]\n\n(SO = NULL)\e[0m\n\n");
	if (!data->we)
		printf("\n\e[91m[PARSING ERROR : NO ALL INFO]\n\n(WE = NULL)\e[0m\n\n");
	if (!data->ea)
		printf("\n\e[91m[PARSING ERROR : NO ALL INFO]\n\n(EA = NULL)\e[0m\n\n");
	if (!data->ff)
		printf("\n\e[91m[PARSING ERROR : NO ALL INFO]\n\n(F = NULL)\e[0m\n\n");
	if (!data->cc)
		printf("\n\e[91m[PARSING ERROR : NO ALL INFO]\n\n(C = NULL)\e[0m\n\n");
}

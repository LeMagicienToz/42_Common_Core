/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:48:06 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/23 17:35:00 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	parsing_name(char *str)
{
	int					i;
	const static char	test[9] = "./cub3D";

	i = 0;
	while (str && str[i])
	{
		if (str[i] != test[i])
			return (1);
		i++;
	}
	return (0);
}

int	parsing_ext(char *str)
{
	int					i;
	int					j;
	const static char	test[5] = ".cub";

	j = 0;
	if (!str)
		return (1);
	i = ft_strlen(str) - 1;
	if (i <= 4)
		return (1);
	while (j < 2)
	{
		if (str[i] != test[3 - j])
			return (1);
		i--;
		j++;
	}
	return (0);
}

int	check_file(char *name)
{
	int	fd;

	if (!name)
		return (1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (close(fd), 1);
	return (close(fd), 0);
}

int	check_codec(char *name)
{
	int		fd;
	char	c;

	fd = open(name, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if ((c < 32 || c > 126) && c != 10)
			return (close(fd), 1);
	}
	return (close(fd), 0);
}

int	check_args(int ac, char **av)
{
	if (ac == 1)
		return (printf("\n\e[91m[PARSING ERROR : CHECK \
		ARGS]\nPLEASE LAUNCH WITH ./cube3d <map.cub> !\n\e[0m"), 1);
	if (ac > 2)
		return (printf("\n\e[91m[PARSING ERROR : CHECK \
		ARGS]\nTOO MANY ARGUMENTS !\n\e[0m"), 1);
	if (parsing_name(av[0]) == 1)
		return (printf("\n\e[91m[PARSING ERROR : CHECK \
		ARGS]\nBAD EXECUTABLE NAME !\n\e[0m"), 1);
	if (parsing_ext(av[1]) == 1)
		return (printf("\n\e[91m[PARSING ERROR : CHECK \
		ARGS]\n\nBAD EXTENSION FOR THE MAP !\n\e[0m"), 1);
	if (check_file(av[1]) == 1)
		return (printf("\n\e[91m[PARSING ERROR : CHECK \
		ARGS]\n\nBAD MAP FILE !\n\e[0m"), 1);
	if (check_codec(av[1]) == 1)
		return (printf("\n\e[91m[PARSING ERROR : CHECK \
		MAP]\n\nBAD CHARACTERS IN MAP FILE !\n\e[0m"), 1);
	return (0);
}

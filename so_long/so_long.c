/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:09:58 by muteza            #+#    #+#             */
/*   Updated: 2022/03/17 13:47:36 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include <fcntl.h>
#include <stdio.h>

char	**ini_first_line(int fd, t_pce *mapi, char *str)
{
	char	**map;
	char	*line;
	t_mapar	mapou;

	mapou.x = 0;
	mapou.y = 0;
	if (!str)
		return (NULL);
	line = check_first_line(fd, mapi, &mapou);
	line = check_map_middle(line, 0, mapi);
	if (!line)
	{
		ft_putstr(" ERROR\n Erreur de parcing ou fichier vide");
		return (NULL);
	}
	map = ft_split(line, '\n');
	free(line);
	if (mapi->p > 1)
		return (NULL);
	map = last_check_map(map, &mapou);
	if (!map)
		ft_putstr("ERROR\n Erreur de parcing ou fichier vide");
	map = check_len(map, &mapou);
	return (map);
}

char	*check_map_middle(char	*str, int i, t_pce *mapi)
{
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 'P' || str[i] == 'C' || str[i] == 'E')
			str = check_pce(str, i++, mapi);
		else
			i++;
	}
	str = check_all_num(mapi, str);
	return (str);
}

char	*check_first_line(int fd, t_pce *mapi, t_mapar *mapou)
{
	char	*line;
	char	*str;
	int		i;

	(void)mapi;
	i = 0;
	line = get_next_line(fd);
	str = NULL;
	if (!line || line[i] == '\n')
		return (NULL);
	while (line)
	{
		str = ft_strjoin(str, line);
		mapou->y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	str = check_un(str, mapou);
	str = check_zero_bn(str);
	return (str);
}

int	main(int argc, char *argv[])
{
	int				fd;
	char			**map;
	char			*str;
	t_pce			mapi;
	t_check			all;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	str = check_if_folder(fd, argv[1]);
	if (!str)
		return (0);
	map = ini_first_line(fd, &mapi, str);
	if (!map)
		return (0);
	all.mlx_mg.mlx = mlx_init();
	go_img(&all, map);
	all.mlx_mg.mlx_win = mlx_new_window(all.mlx_mg.mlx, all.mlx_mg.width, \
			all.mlx_mg.height, "so_long");
	all.mlx_mg.img = mlx_new_image(all.mlx_mg.mlx, \
		all.mlx_mg.height, all.mlx_mg .width);
	pos_pcea(map, &all);
	mlx_key_hook(all.mlx_mg.mlx_win, hooks_goos, &all);
	mlx_hook(all.mlx_mg.mlx_win, 17, 1L << 0, exit_two, &all);
	mlx_loop(all.mlx_mg.mlx);
}

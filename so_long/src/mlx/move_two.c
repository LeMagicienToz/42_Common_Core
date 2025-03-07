/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:59:57 by muteza            #+#    #+#             */
/*   Updated: 2022/03/17 13:38:04 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	finish_collect(t_check *all)
{
	if (all->nb_col == 0)
	{
	all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
	"src/sprite/UwU.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
	all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
	all->player.pos.y += 64;
		move_frame_new_pos(all, "src/sprite/UwU.xpm");
		return (0);
	}
	else
	{
		all->p_pos.y++;
		all->mlx_mg.img = mlx_xpm_file_to_image(all->mlx_mg.mlx, \
			"src/sprite/grass.xpm", &all->mlx_mg.width, &all->mlx_mg.height);
		mlx_put_image_to_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win, \
			all->mlx_mg.img, all->player.pos.x, all->player.pos.y);
		all->player.pos.y += 64;
		move_frame_new_pos(all, "src/sprite/goose_ak.xpm");
	}
	return (1);
}

void	exit_esc(t_check *all)
{
	int	i;

	i = 0;
	mlx_destroy_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win);
	while (all->map[i])
	{
		free(all->map[i++]);
	}
	exit(0);
}

char	*check_all_num(t_pce *mapi, char *str)
{
	if (mapi->p != 1)
		str = NULL;
	if (mapi->e < 1)
		str = NULL;
	if (mapi->c < 1)
		str = NULL;
	return (str);
}

int	exit_two(t_check *all)
{
	int	i;

	i = 0;
	mlx_destroy_window(all->mlx_mg.mlx, all->mlx_mg.mlx_win);
	while (all->map[i])
	{
		free(all->map[i++]);
	}
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_allpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:50:40 by muteza            #+#    #+#             */
/*   Updated: 2022/03/15 13:40:55 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_exit_layer(t_check *all)
{
	all->exit.pos.x = 0;
	all->exit.pos.y = 0;
	all->exit.size.x = 64;
	all->exit.size.y = 64;
	all->move_count = 1;
	check_player_layer(all);
}

void	check_player_layer(t_check *all)
{
	all->player.img = "src/sprite/goose_zk.xpm";
	check_collect_layer(all);
}

void	check_collect_layer(t_check *all)
{
	all->collect.pos.x = 0;
	all->collect.pos.y = 0;
	all->collect.size.x = 64;
	all->collect.size.y = 64;
	all->collect.img = "sprite/tscott.xpm";
	check_wall_layer(all);
}

void	check_wall_layer(t_check *all)
{
	all->wall.pos.x = 0;
	all->wall.pos.y = 0;
	all->wall.size.x = 64;
	all->wall.size.y = 64;
	all->wall.img = "sprite/wall.xpm";
	check_grass_layer(all);
}

void	check_grass_layer(t_check *all)
{
	all->grass.pos.x = 0;
	all->grass.pos.y = 0;
	all->grass.size.x = 64;
	all->grass.size.y = 64;
	all->grass.img = "src/sprite/grass.xpm";
}

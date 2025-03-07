/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:22:33 by muteza            #+#    #+#             */
/*   Updated: 2022/03/16 18:26:34 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_walk_down(t_check *all)
{
	ft_putnbr(all->move_count);
	ft_putchar('\n');
	all->move_count++;
}

void	print_walk_right(t_check *all)
{
	ft_putnbr(all->move_count);
	ft_putchar('\n');
	all->move_count++;
}

void	print_walk_top(t_check *all)
{
	ft_putnbr(all->move_count);
	ft_putchar('\n');
	all->move_count++;
}

void	print_walk_left(t_check *all)
{
	ft_putnbr(all->move_count);
	ft_putchar('\n');
	all->move_count++;
}

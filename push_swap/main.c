/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:12:58 by muteza            #+#    #+#             */
/*   Updated: 2022/06/11 14:55:51 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parcing_args(char **argv, int argc, t_exec *all)
{
	if (argc == 2)
		sotck_tab_in_lst_string(argv, all);
	if (argc > 2)
		sotck_in_tab(argv, all);
	return (1);
}

void	sotck_tab_in_lst_string(char **argv, t_exec *all)
{
	int		i;

	i = 0;
	all->str = argv[1];
	if (is_nbr_double(all) == 0)
		exit(write(1, "Arguments goes wrong", 20));
	all->tab_a = ft_split(all->str, ' ');
	if (is_trillable(all) == 0)
		exit(0);
	all->a = ft_lstnew(ft_atoi(all->tab_a[i]));
	while (all->tab_a[++i])
		ft_lstadd_back(&all->a, ft_lstnew(ft_atoi(all->tab_a[i])));
	make_a(all, i);
	if (i != 3 && i != 5)
		algo_sorted(all);
	if (i == 5)
		algo_five(all);
	if (i == 3)
		algo_third(all);
}

void	sotck_in_tab(char **str, t_exec *all)
{
	int	i;

	i = 1;
	while (str[i])
	{
		all->str = ft_strjoin(all->str, str[i]);
		all->str = ft_strjoin(all->str, " ");
		i++;
	}
	str[1] = all->str;
	sotck_tab_in_lst_string(str, all);
}

int	main(int argc, char **argv)
{
	t_exec	all;

	all.v = 0;
	if (argc > 1 && parcing_args(argv, argc, &all))
		return (0);
}

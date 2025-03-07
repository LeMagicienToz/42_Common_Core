/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:37:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/28 16:44:29 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_map(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		data->error_line = j;
		while (data->map[j][i])
		{
			if (ft_strncmp("10 NSWEKO", data->map[j][i]))
				return (print_map(data, data->map), printf("\n\e[91m[PARSING ERROR : \
				CHECK MAP]\n\n(line %d) ==> [%s]\e[0m\n\n", \
				data->error_line + 1, data->map[data->error_line]), 1);
			if (!ft_strncmp("NSWE0KO", data->map[j][i]) && j == data->lin - 1)
				return (print_map(data, data->map), printf("\n\e[91m[PARSING ERROR : \
				CHECK MAP]\n\n(line %d) ==> [%s]\e[0m\n\n", \
				data->error_line + 1, data->map[data->error_line]), 1);
			i++;
		}
		i = 0;
		j++;
	}
	return (printf("\nCHECK MAP [\e[92mOK\e[0m]\n"), 0);
}

void	check_walls_end(t_data *data)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'X')
				data->map[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
}

int	make_all_test(t_data *data, int argc, char **argv)
{
	data->error_line = -1;
	(norm_check_infos(), data->so = NULL, data->no = NULL, \
	data->we = NULL, data->ea = NULL, data->ff = NULL, data->cc = NULL, \
	data->info_error = 0, data->del = NULL, data->face_save = NULL);
	printf("\n== TESTING THE ARGS ==\n\n");
	if (check_args(argc, argv))
		return (1);
	printf("ARGS CHECK [\e[92mOK\e[0m]\n");
	init_map(argv[1], data);
	printf("\n== TESTING THE FILE ==\n");
	print_map(data, data->map);
	printf("\n== PARSER RESULT ==\n");
	if (check_infos(data) || check_img_init(data))
		return (1);
	remove_info(data);
	if (check_infos_rgb_f(data) || check_infos_rgb_c(data) || check_map(data))
		return (1);
	if (get_face(data, 0, 0))
		return (1);
	if (check_walls(data, 0, 0) || check_map(data))
		return (1);
	return (printf("\nPARSING : [\e[92mSUCCESS\e[0m]\n\n"), \
	print_good_map(data, data->map), convert_rgb_to_hex(data), 0);
}

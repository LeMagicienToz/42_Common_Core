/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_third.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:16 by muteza            #+#    #+#             */
/*   Updated: 2022/03/14 18:38:36 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_zero_bn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 'P' || str[i] == 'C' || str[i] == 'E'
			|| str[i] == '1' || str[i] == '0' || str[i] == '\n')
		{
			if (str[i] == '\n' && str[i + 1] == '\n')
				return (NULL);
			i++;
		}
		else
			return (NULL);
	}
	return (str);
}

char	*check_error_file(char *str)
{
	int		i;
	int		k;
	char	tmp[5];

	k = 0;
	i = ft_strlen(str) - 5;
	while (str[i++])
		tmp[k++] = str[i];
	k = ft_strncmp(".ber", tmp, 5);
	if (k == 0)
	{
		return (str);
	}
	else
	{
		ft_putstr("ERROR\n Erreur d'Extention");
		return (NULL);
	}
}

char	*check_if_folder(int fd, char *str)
{
	char	buff[1];
	int		rb;

	if (fd < 0)
	{
		ft_putstr("ERROR\n Fichier inexistant / probleme d'ouverture");
		return (NULL);
	}
	rb = read(fd, buff, 0);
	if (rb < 0)
	{
		ft_putstr("ERROR\n Fichier inexistant");
		return (NULL);
	}
	else
	{
		return (check_error_file(str));
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (n != '\0' && i < n))
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else if (s1[i] < s2[i])
		{
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		}
		else
			return (1);
	}
	return (0);
}

void	go_img(t_check *all, char **map)
{
	all->mlx_mg.width = ft_strlen(map[0]) * 64;
	all->mlx_mg.height = ft_strlen_y(map) * 64;
	all->mlx_mg.img = 0;
}

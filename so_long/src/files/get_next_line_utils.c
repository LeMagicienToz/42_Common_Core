/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:01:37 by muteza            #+#    #+#             */
/*   Updated: 2022/02/07 18:14:28 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	tmp = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i] != '\0')
			tmp[i] = str[i];
	j = 0;
	while (buf[j] != '\0')
		tmp[i++] = buf[j++];
	tmp[ft_strlen(str) + ft_strlen(buf)] = '\0';
	free (str);
	return (tmp);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

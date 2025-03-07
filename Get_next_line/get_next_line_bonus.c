/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:25:44 by muteza            #+#    #+#             */
/*   Updated: 2021/12/03 12:19:31 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*save[FOPEN_MAX];
	char		*line;

	if (read(fd, save[fd], 0) < 0)
		return (NULL);
	save[fd] = get_line(save[fd], fd);
	if (save[fd] == NULL || fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = good_line(save[fd]);
	save[fd] = new_buff(save[fd]);
	return (line);
}

char	*good_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*new_buff(char *save)
{
	int		i;
	int		k;
	char	*new_save;

	i = 0;
	k = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = ft_calloc(sizeof(char), ft_strlen(save) - i + 1);
	if (new_save == 0)
		return (NULL);
	i++;
	while (save[i])
		new_save[k++] = save[i++];
	new_save[k] = '\0';
	free(save);
	return (new_save);
}

char	*get_line(char *save, int fd)
{
	int		ret;
	char	*buff;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	ret = 1;
	while (!ft_strchr(save, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[ret] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

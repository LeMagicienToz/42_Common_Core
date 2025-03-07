/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:11:35 by muteza            #+#    #+#             */
/*   Updated: 2021/12/02 13:25:41 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *str, char *buf);
char	*get_line(char *str, int ret);
char	*good_line(char *save);
char	*new_buff(char *save);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:30:26 by muteza            #+#    #+#             */
/*   Updated: 2022/04/12 17:04:44 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_exec{
	int			fd[2];
	int			f3;
	int			f1;
	pid_t		id;
	char		**f_com;
	char		**s_com;
	char		*path_first;
	char		*path_second;
}t_exec;

int		redirection_exec(t_exec *all);
int		parcing_arguments(int nb_arg, char **str, char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(char *s);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);
char	*ft_strjoin(char *str, char *buf);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, char *src);
char	*check_access_second(t_exec *all, char **str, char *path);
char	*check_access_first(t_exec *all, char **str, char *path);
char	*check_second_command(t_exec *all, char **str, char **env);
char	*check_first_command(t_exec *all, char **str, char **env);

void	free_path(char **str, char *path);
void	check_files(t_exec *all, char **str);
void	fork_ini(t_exec *all);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
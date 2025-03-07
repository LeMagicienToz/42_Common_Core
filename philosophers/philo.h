/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:44:45 by muteza            #+#    #+#             */
/*   Updated: 2022/10/03 08:34:51 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>

typedef struct t_mutex{
	pthread_mutex_t		*mu_death;
	pthread_mutex_t		*fork;
	pthread_mutex_t		die;
	pthread_mutex_t		print;
}t_mutex;

typedef struct s_exec{
	char				**str;
	int					nb_philo;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			nb_eat;
	long				time_ms;
	long int			time_to_start;
	int					nb_philo_who_ate_enough;
	int					alive;
	pthread_mutex_t		exit;
}t_exec;

typedef struct s_philo{
	pthread_t			ph;
	long int			last_eat;
	int					philo_id;
	int					fork_right;
	int					fork_left;
	long				food_count;

	t_exec				*parc;
	t_mutex				*mutex;
}t_philo;

void		*thread_un(t_exec *parc, t_philo *philo);

long int	actual_time(void);

long		get_time(void);

void		philo_think(t_philo *philo);
void		ft_print(t_philo *philo, char *code);
void		ini_mutex(t_mutex *mutex, t_exec *parc);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo);
void		ft_usleep(long int ms);
void		ini_philo(t_exec *parc, t_philo *philo, t_mutex *mutex);

int			ft_is_number(char **str);
int			ft_atoi(char *str);
int			parcing_philo(t_exec *all);
int			ft_atoll(char *str);
#endif
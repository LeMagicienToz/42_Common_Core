/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:14:40 by muteza            #+#    #+#             */
/*   Updated: 2022/10/03 07:58:58 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_philo(t_exec *parc, t_philo *philo, t_mutex *mutex)
{
	int	i;

	i = 0;
	while (i < parc->nb_philo)
	{
		parc->nb_philo_who_ate_enough = 0;
		parc->alive = 1;
		philo[i].mutex = mutex;
		philo[i].parc = parc;
		philo[i].philo_id = i + 1;
		philo[i].food_count = 0;
		philo[i].fork_right = i;
		philo[i].fork_left = (i + 1) % parc->nb_philo;
		i++;
	}
}

void	ini_mutex(t_mutex *mutex, t_exec *parc)
{
	int	i;

	i = parc->nb_philo;
	pthread_mutex_init(&mutex->print, NULL);
	pthread_mutex_init(&mutex->die, NULL);
	mutex->mu_death = malloc(sizeof(pthread_mutex_t) * parc->nb_philo);
	mutex->fork = malloc(sizeof(pthread_mutex_t) * parc->nb_philo);
	while (i > 0)
	{
		pthread_mutex_init(&mutex->fork[i], NULL);
		pthread_mutex_init(&mutex->mu_death[i], NULL);
		i--;
	}
}

long int	actual_time(void)
{
	long int		time;
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	time = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int ms)
{
	long	time;

	time = get_time();
	while ((get_time() - time) < ms)
		usleep(500);
}

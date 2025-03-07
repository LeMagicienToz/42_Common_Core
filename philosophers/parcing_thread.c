/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:43:26 by muteza            #+#    #+#             */
/*   Updated: 2022/10/03 08:39:43 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*die_time(t_philo *philo)
{
	if (get_time() > philo->last_eat + philo->parc->time_to_die)
	{
		ft_print(philo, "DIE");
		pthread_mutex_unlock(&philo->parc->exit);
	}
	return (NULL);
}

void	*checker(void *argv)
{
	t_philo		*philo;

	philo = (t_philo *)argv;
	while (philo->parc->alive == 1)
	{
		die_time(philo);
		ft_usleep(1);
	}
	return (0);
}

void	*routine(void *argv)
{
	t_philo		*philo;
	pthread_t	check;

	philo = (t_philo *)argv;
	philo->last_eat = get_time();
	pthread_create(&check, NULL, &checker, philo);
	while (philo->parc->alive == 1)
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->fork_left]);
		ft_print(philo, "FORK");
		pthread_mutex_lock(&philo->mutex->fork[philo->fork_right]);
		ft_print(philo, "FORK");
		philo_eat(philo);
	}
	pthread_join(check, NULL);
	return (NULL);
}

void	*thread_un(t_exec *parc, t_philo *philo)
{
	int		i;

	philo->parc->time_to_start = get_time();
	i = 1;
	while (i < parc->nb_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &routine, &philo[i]);
		i += 2;
	}
	ft_usleep(100);
	i = 0;
	while (i < parc->nb_philo)
	{
		pthread_create(&(philo[i].ph), NULL, &routine, &philo[i]);
		i += 2;
	}
	return (0);
}

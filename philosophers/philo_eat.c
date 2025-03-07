/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:40:29 by muteza            #+#    #+#             */
/*   Updated: 2022/10/03 08:41:26 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	ft_print(philo, "EAT");
	philo->last_eat = actual_time();
	ft_usleep(philo->parc->time_to_eat);
	philo->last_eat = get_time();
	philo->food_count++;
	if (philo->parc->nb_eat == philo->food_count && philo->parc->alive == 1)
	{
		philo->parc->nb_philo_who_ate_enough++;
		if (philo->parc->nb_philo_who_ate_enough == philo->parc->nb_philo)
		{
			philo->parc->alive = 0;
			pthread_mutex_lock(&philo->mutex->print);
			printf("!!! !!! SIUU I ate too much UwU !!! !!!\n");
			pthread_mutex_unlock(&philo->parc->exit);
			pthread_mutex_unlock(&philo->mutex->print);
		}
	}
	pthread_mutex_unlock(&philo->mutex->fork[philo->fork_right]);
	pthread_mutex_unlock(&philo->mutex->fork[philo->fork_left]);
	philo_sleep(philo);
}

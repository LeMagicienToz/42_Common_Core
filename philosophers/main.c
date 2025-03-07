/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:35:55 by muteza            #+#    #+#             */
/*   Updated: 2022/10/03 08:59:11 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_parcing(t_exec *parc)
{
	if (parc->nb_philo <= 0)
		return (0);
	if (parc->str[5] != NULL && parc->nb_eat <= 0)
		return (0);
	if (parc->time_to_die <= 0)
		return (0);
	if (parc->time_to_eat <= 0)
		return (0);
	if (parc->time_to_sleep <= 0)
		return (0);
	return (1);
}	

int	parcing_arguments(t_exec *parc)
{
	if (ft_atoi(parc->str[1]) > 200 && ft_atoi(parc->str[1]) != 0)
		return (0);
	if (parc->str[5] != NULL)
		parc->nb_eat = ft_atoll(parc->str[5]);
	parc->nb_philo = ft_atoi(parc->str[1]);
	parc->time_to_die = ft_atoll(parc->str[2]);
	parc->time_to_eat = ft_atoll(parc->str[3]);
	parc->time_to_sleep = ft_atoll(parc->str[4]);
	if (ft_is_number(parc->str) == 1)
		return (0);
	if (check_parcing(parc) == 0)
		return (0);
	else
		return (1);
}

long	get_time(void)
{
	long			time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	time = tv.tv_sec * 1000;
	time = time + tv.tv_usec / 1000;
	return (time);
}

int	main(int argc, char **argv)
{
	t_exec	parc;
	t_philo	*philo;
	t_mutex	mutex;

	parc.str = argv;
	if ((argc != 6 && argc != 5) || parcing_arguments(&parc) == 0)
	{
		printf("Erreur Parcing");
		return (0);
	}
	philo = malloc(sizeof(t_philo) * parc.nb_philo);
	ini_mutex(&mutex, &parc);
	ini_philo(&parc, philo, &mutex);
	pthread_mutex_init(&parc.exit, NULL);
	pthread_mutex_lock(&parc.exit);
	thread_un(&parc, philo);
	pthread_mutex_lock(&parc.exit);
	return (0);
}

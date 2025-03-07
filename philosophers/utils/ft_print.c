/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:20:59 by muteza            #+#    #+#             */
/*   Updated: 2022/10/03 08:31:42 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_print(t_philo *philo, char *code)
{
	long int	time_now;

	time_now = actual_time() - philo->parc->time_to_start;
	pthread_mutex_lock(&philo->mutex->print);
	if (philo->parc->alive == 1)
	{
		if (ft_strcmp(code, "FORK") == 0)
			printf("%ld %d has taken a fork\n", time_now, philo->philo_id);
		if (ft_strcmp(code, "EAT") == 0)
			printf("%ld %d is eating\n", time_now, philo->philo_id);
		if (ft_strcmp(code, "SLEEP") == 0)
			printf("%ld %d is sleeping\n", time_now, philo->philo_id);
		if (ft_strcmp(code, "THINK") == 0)
			printf("%ld %d is thinking\n", time_now, philo->philo_id);
		if (ft_strcmp(code, "DIE") == 0)
		{
			philo->parc->alive = 0;
			printf("%ld %d died\n", time_now, philo->philo_id);
		}
	}
	pthread_mutex_unlock(&philo->mutex->print);
}

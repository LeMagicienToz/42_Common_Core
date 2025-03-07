/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:14:35 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/06/23 20:16:57 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_neg(char *str)
{
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	while (str[i] && !ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			neg = -1;
		else if (str[i] == '+')
			neg = 1;
		i++;
	}
	return (neg);
}

static int	ft_strcompare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	int_max_or_min(char *str)
{
	if (ft_strcompare(str, "-2147483648") == 0)
		return (INT_MIN);
	else if (ft_strcompare(str, "2147483647") == 0)
		return (INT_MAX);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		n;
	int		i;
	int		neg;

	n = 0;
	i = 0;
	if ((ft_strcompare(str, "-2147483648") == 0))
		return (int_max_or_min(str));
	else if ((ft_strcompare(str, "2147483647") == 0))
		return (int_max_or_min(str));
	neg = (ft_neg(str));
	while (str[i] && ((str[i] > 8 && str[i] < 14) || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		n *= 10;
		n += (str[i] - '0');
		i++;
	}
	return (n * neg);
}

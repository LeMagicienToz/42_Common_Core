/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:50:23 by muteza            #+#    #+#             */
/*   Updated: 2022/04/04 17:50:40 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_nbrlen(int c)
{
	int	i;

	i = 0;
	if (c < 0)
	{
		c *= -1;
		i++;
	}
	while (c > 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

char	*ft_gest_fill(long n, char *dest, int *i)
{
	if (n > 9)
	{
		ft_gest_fill(n / 10, dest, i);
		ft_gest_fill(n % 10, dest, i);
	}
	else
		dest[(*i)++] = n + 48;
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	nbr;

	nbr = n;
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_nbrlen(nbr) + 1));
	if (!dest)
		return (NULL);
	if (n < 0)
	{
		dest[i++] = '-';
		nbr = nbr * -1;
	}
	dest = ft_gest_fill(nbr, dest, &i);
	dest[i] = '\0';
	return (dest);
}

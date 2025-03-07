/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:28:19 by muteza            #+#    #+#             */
/*   Updated: 2023/06/23 17:28:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	size_t	i;
	char	*s1;

	s1 = (char *)dst;
	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		*(char *)s1 = *(char *)src;
		s1++;
		src++;
		i++;
	}
	return (dst);
}

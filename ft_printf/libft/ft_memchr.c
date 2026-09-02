/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:02:21 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 13:02:25 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*target;
	size_t				i;

	target = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (target[i] == (unsigned char)c)
		{
			return ((void *)(target + i));
		}
		i++;
	}
	return (NULL);
}

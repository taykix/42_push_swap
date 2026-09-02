/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:49:36 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 11:55:01 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 12:56:49 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 12:56:51 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_size;

	s_size = ft_strlen(s);
	while (s_size >= 0)
	{
		if (s[s_size] == (char)c)
		{
			return ((char *)s + s_size);
		}
		s_size--;
	}
	return (NULL);
}

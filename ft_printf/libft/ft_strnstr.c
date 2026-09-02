/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:20:38 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 13:21:14 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;
	size_t	big_len;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (little_len == 0)
		return ((char *)big);
	if (big_len < little_len || len < little_len)
		return (NULL);
	i = 0;
	while (i <= len - little_len && i <= big_len - little_len)
	{
		j = 0;
		while (j < little_len && big[i + j] == little[j])
		{
			j++;
		}
		if (j == little_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

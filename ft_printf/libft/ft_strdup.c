/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:22:29 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 13:22:40 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*arr;
	char	*ptr;

	len_s = ft_strlen(s);
	arr = malloc((len_s + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	ptr = arr;
	while (*s)
	{
		*arr++ = *s++;
	}
	*arr = '\0';
	return (ptr);
}

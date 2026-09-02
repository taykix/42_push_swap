/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 19:34:37 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/01 19:36:59 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int	parity;
	long	result;
	int	sign_count;

	result = 0;
	parity = 1;
	sign_count = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		++nptr;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			parity *= -1;
		++nptr;
		sign_count++;
	}
	if (sign_count > 1)
		return (0);
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		++nptr;
	}
	return (result * parity);
}

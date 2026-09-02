/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:21:47 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 13:21:49 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	parity;
	int	result;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 14:06:11 by takaraka          #+#    #+#             */
/*   Updated: 2026/07/10 14:06:13 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(long long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*str;
	long int	num;

	count = count_digit(n);
	num = n;
	if (n < 0)
	{
		num *= -1;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!(str))
		return (NULL);
	*(str + count) = 0;
	while (count--)
	{
		*(str + count) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
	{
		*(str + 0) = '-';
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsbur      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 09:39:32 by takaraka          #+#    #+#             */
/*   Updated: 2026/08/14 09:39:35 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr_arg(va_list args, int *p_len)
{
	unsigned long long	d;

	d = (unsigned long long)va_arg(args, unsigned long long);
	if (d == 0)
	{
		ft_putstr("(nil)");
		(*p_len) += 5;
	}
	else
	{
		ft_putstr("0x");
		(*p_len) += 2;
		ft_puthexnbr(d);
		while (d != 0)
		{
			(*p_len)++;
			d /= 16;
		}
	}
}

void	ft_print_hexl_arg(va_list args, int *p_len)
{
	unsigned int	d;

	d = (unsigned int)va_arg(args, unsigned int);
	ft_puthexnbr(d);
	if (d == 0)
		(*p_len)++;
	while (d != 0)
	{
		(*p_len)++;
		d /= 16;
	}
}

void	ft_print_hexb_arg(va_list args, int *p_len)
{
	unsigned int	d;

	d = (unsigned int)va_arg(args, unsigned int);
	ft_puthexnbrbig(d);
	if (d == 0)
		(*p_len)++;
	while (d != 0)
	{
		(*p_len)++;
		d /= 16;
	}
}

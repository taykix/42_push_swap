/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 03:36:23 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/12 09:25:22 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	hundredths;

	hundredths = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(hundredths / 100, 2);
	ft_putchar_fd('.', 2);
	if (hundredths % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(hundredths % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	print_count(char *name, int count)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

static int	total_operations(t_counter *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb + c->ra + c->rb + c->rr
		+ c->rra + c->rrb + c->rrr);
}

void	print_bench(t_argument *flags, t_counter *counter)
{
	print_disorder(flags->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *)flags->name, 2);
	if (flags->is_adaptive)
		ft_putendl_fd(" [selected by adaptive]", 2);
	else
		ft_putendl_fd(" [forced by flag]", 2);
	print_count("total operations", total_operations(counter));
	print_count("sa", counter->sa);
	print_count("sb", counter->sb);
	print_count("ss", counter->ss);
	print_count("pa", counter->pa);
	print_count("pb", counter->pb);
	print_count("ra", counter->ra);
	print_count("rb", counter->rb);
	print_count("rr", counter->rr);
	print_count("rra", counter->rra);
	print_count("rrb", counter->rrb);
	print_count("rrr", counter->rrr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 23:24:50 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/07 16:48:59 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	stack_a->counter->sa++;
}

void	op_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	stack_b->counter->sb++;
}

void	op_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	stack_a->counter->ss++;
}

void	op_pa(t_stack *stack_a, t_stack *stack_b)
{
	push_to(stack_a, stack_b);
	ft_printf("pa\n");
	stack_a->counter->pa++;
}

void	op_pb(t_stack *stack_a, t_stack *stack_b)
{
	push_to(stack_b, stack_a);
	ft_printf("pb\n");
	stack_a->counter->pb++;
}

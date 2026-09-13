/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 13:26:38 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/05 05:41:23 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	stack_a->counter->ra++;
}

void	op_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	stack_b->counter->rb++;
}

void	op_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	stack_a->counter->rr++;
}

void	op_rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	stack_a->counter->rra++;
}

void	op_rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	stack_b->counter->rrb++;
}

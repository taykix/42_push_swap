/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 20:13:39 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/10 13:58:39 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* number of bits needed to write the largest rank (n - 1) */
static int	count_bits(int n)
{
	int	bits;
	int	max_rank;

	bits = 0;
	max_rank = n - 1;
	while (max_rank > 0)
	{
		max_rank >>= 1;
		bits++;
	}
	return (bits);
}

/*
** One LSD pass: elements whose current bit is 0 go to b, the others are
** rotated to the bottom of a. Pushing everything back restores the relative
** order, so the pass is stable.
*/
static void	radix_pass(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	i;
	int	size;

	size = stack_a->element_count;
	i = 0;
	while (i < size)
	{
		if ((stack_a->head->rank >> bit) & 1)
			op_ra(stack_a);
		else
			op_pb(stack_a, stack_b);
		i++;
	}
	while (!is_empty(stack_b))
		op_pa(stack_a, stack_b);
}

void	sort_complex(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	bits;

	set_ranks(stack_a);
	bits = count_bits(stack_a->element_count);
	bit = 0;
	while (bit < bits && !is_sorted(stack_a))
	{
		radix_pass(stack_a, stack_b, bit);
		bit++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:57:35 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/13 09:42:23 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* smallest s with s * s >= n, i.e. ceil(sqrt(n)) without libm */
static int	chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

/*
** Phase 1: one-directional scan of a. The window of pushable ranks is
** [0, pushed + size). An element whose rank lies in the lower half of the
** window is sent to the bottom of b (rb) so that b keeps its largest
** elements close to both ends.
*/
static void	push_chunks(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	limit;

	while (!is_empty(stack_a))
	{
		limit = stack_b->element_count + size;
		if (stack_a->head->rank < limit)
		{
			op_pb(stack_a, stack_b);
			if (stack_b->head->rank < limit - size / 2)
				op_rb(stack_b);
		}
		else
			op_ra(stack_a);
	}
}

/* Phase 2: bring the current maximum of b to the top (shortest way), pa. */
static void	pull_back(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_empty(stack_b))
	{
		set_indexes(stack_b);
		rotate_node_to_top(stack_b, find_max(stack_b), 'b');
		op_pa(stack_a, stack_b);
	}
}

void	sort_medium(t_stack *stack_a, t_stack *stack_b)
{
	set_ranks(stack_a);
	push_chunks(stack_a, stack_b, chunk_size(stack_a->element_count));
	pull_back(stack_a, stack_b);
}

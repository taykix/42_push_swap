/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 21:29:32 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/10 06:00:57 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->head == find_max(stack))
		op_ra(stack);
	else if (stack->head->next == find_max(stack))
		op_rra(stack);
	if (!is_sorted(stack))
		op_sa(stack);
}

void	sort_simple(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->element_count > 3 && !is_sorted(stack_a))
		op_pb(stack_a, stack_b);
	if (stack_a->element_count > 3 && !is_sorted(stack_a))
		op_pb(stack_a, stack_b);
	while (stack_a->element_count > 3 && !is_sorted(stack_a))
	{
		get_stack_ready(stack_a, stack_b, 'a');
		nodes_a_to_b(stack_a, stack_b);
	}
	if (!is_sorted(stack_a) && stack_a->element_count == 3)
		sort_three(stack_a);
	while (stack_b->element_count > 0)
	{
		get_stack_ready(stack_a, stack_b, 'b');
		nodes_b_to_a(stack_a, stack_b);
	}
	set_indexes(stack_a);
	rotate_node_to_top(stack_a, find_min(stack_a), 'a');
}

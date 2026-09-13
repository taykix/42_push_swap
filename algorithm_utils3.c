/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:56:15 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/12 13:14:29 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	economic_rotate(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(stack_a);
	if (cheapest_node->is_above_median && cheapest_node->target->is_above_median
		&& cheapest_node->index != 0 && cheapest_node->target->index != 0)
	{
		op_rr(stack_a, stack_b);
		set_indexes(stack_a);
		set_indexes(stack_b);
	}
	else if (!cheapest_node->is_above_median
		&& !cheapest_node->target->is_above_median && cheapest_node->index != 0
		&& cheapest_node->target->index != 0)
	{
		op_rrr(stack_a, stack_b);
		set_indexes(stack_a);
		set_indexes(stack_b);
	}
}

void	nodes_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(stack_a);
	economic_rotate(stack_a, stack_b);
	if (rotate_node_to_top(stack_a, cheapest_node, 'a')
		&& rotate_node_to_top(stack_b, cheapest_node->target, 'b'))
		op_pb(stack_a, stack_b);
}

void	nodes_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate_node_to_top(stack_a, stack_b->head->target, 'a'))
		op_pa(stack_a, stack_b);
}

void	get_stack_ready(t_stack *stack_a, t_stack *stack_b, char stack_name)
{
	set_indexes(stack_a);
	set_indexes(stack_b);
	reset_cheapest(stack_a);
	reset_cheapest(stack_b);
	if (stack_name == 'a')
	{
		set_target_a(stack_a, stack_b);
		cost_analysis_a(stack_a, stack_b);
		set_cheapest(stack_a);
	}
	else if (stack_name == 'b')
	{
		set_target_b(stack_b, stack_a);
	}
}

void	reset_cheapest(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		temp->is_cheapest = 0;
		temp = temp->next;
	}
}

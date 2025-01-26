/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:50 by tayki             #+#    #+#             */
/*   Updated: 2025/01/25 18:15:59 by tayki            ###   ########.fr       */
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
		rotate(stack_a);
		set_indexes(stack_a);
		rotate(stack_b);
		set_indexes(stack_b);
		ft_printf("rr\n");
	}
	else if (!cheapest_node->is_above_median
		&& !cheapest_node->target->is_above_median && cheapest_node->index != 0
		&& cheapest_node->target->index != 0)
	{
		reverse_rotate(stack_a);
		set_indexes(stack_a);
		reverse_rotate(stack_b);
		set_indexes(stack_b);
		ft_printf("rrr\n");
	}
}

void	nodes_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(stack_a);
	economic_rotate(stack_a, stack_b);
	if (rotate_node_to_top(stack_a, cheapest_node, 'a')
		&& rotate_node_to_top(stack_b, cheapest_node->target, 'b'))
	{
		push_to(stack_b, stack_a);
		ft_printf("pb\n");
	}
	else
		ft_printf("EROR with rotating cheapest to top pa\n");
}

void	nodes_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate_node_to_top(stack_a, stack_b->head->target, 'a'))
	{
		push_to(stack_a, stack_b);
		ft_printf("pa\n");
	}
	else
		ft_printf("EROR with rotating b's target to top\n");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:28 by tayki             #+#    #+#             */
/*   Updated: 2025/01/26 15:28:29 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->head == find_max(stack))
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	else if (stack->head->next == find_max(stack))
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if (!is_sorted(stack))
	{
		swap(stack);
		ft_printf("sa\n");
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->element_count > 3 && !is_sorted(stack_a))
	{
		push_to(stack_b, stack_a);
		ft_printf("pb\n");
	}
	if (stack_a->element_count > 3 && !is_sorted(stack_a))
	{
		push_to(stack_b, stack_a);
		ft_printf("pb\n");
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 20:46:20 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/11 02:36:39 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack *stack)
{
	t_node	*temp;
	t_node	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	temp = stack->head;
	cheapest_value = LONG_MAX;
	while (temp)
	{
		if (temp->push_cost < cheapest_value)
		{
			cheapest_value = temp->push_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
	cheapest_node->is_cheapest = 1;
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return (NULL);
	temp = stack->head;
	while (temp)
	{
		if (temp->is_cheapest)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	set_target_b(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node	*target;
	long	best_match;

	temp_b = stack_b->head;
	while (temp_b)
	{
		temp_a = stack_a->head;
		best_match = LONG_MAX;
		while (temp_a)
		{
			if (temp_a->data > temp_b->data && temp_a->data < best_match)
			{
				best_match = temp_a->data;
				target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match == LONG_MAX)
			temp_b->target = find_min(stack_a);
		else
			temp_b->target = target;
		temp_b = temp_b->next;
	}
}

t_node	*find_min(t_stack *stack)
{
	t_node	*temp;
	t_node	*min;

	temp = stack->head;
	min = temp;
	while (temp)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

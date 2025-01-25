/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:41 by tayki             #+#    #+#             */
/*   Updated: 2025/01/24 19:36:56 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		min;
	t_node	*temp;

	if (stack->element_count < 2)
		return (1);
	temp = stack->head;
	min = temp->data;
	temp = temp->next;
	while (temp)
	{
		if (temp->data < min)
		{
			return (0);
		}
		min = temp->data;
		temp = temp->next;
	}
	return (1);
}

void	set_indexes(t_stack *stack)
{
	t_node	*temp;
	int		index;
	int		median;

	temp = stack->head;
	index = 0;
	median = stack->element_count / 2;
	while (temp != NULL)
	{
		temp->index = index;
		if (index <= median)
		{
			temp->is_above_median = 1;
		}
		else
		{
			temp->is_above_median = 0;
		}
		temp = temp->next;
		index++;
	}
}

void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node	*target;
	long	best_match;

	temp_a = stack_a->head;
	while (temp_a)
	{
		temp_b = stack_b->head;
		best_match = LONG_MIN;
		while (temp_b)
		{
			if (temp_b->data < temp_a->data && temp_b->data > best_match)
			{
				best_match = temp_b->data;
				target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match == LONG_MIN)
			temp_a->target = find_max(stack_b);
		else
			temp_a->target = target;
		temp_a = temp_a->next;
	}
}

void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;

	temp_a = stack_a->head;
	while (temp_a)
	{
		temp_a->push_cost = temp_a->index;
		if (!(temp_a->is_above_median))
			temp_a->push_cost = stack_a->element_count - temp_a->index;
		if (temp_a->target->is_above_median)
			temp_a->push_cost += temp_a->target->index;
		else
			temp_a->push_cost += stack_b->element_count - temp_a->target->index;
		temp_a = temp_a->next;
	}
}

t_node	*find_max(t_stack *stack)
{
	t_node	*temp;
	t_node	*max;

	temp = stack->head;
	max = temp;
	while (temp)
	{
		if (temp->data > max->data)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

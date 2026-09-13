/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:42:29 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/10 10:25:01 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->head == NULL);
}

void	push(t_stack *stack, int data)
{
	insert_before_head(stack, data);
}

int	pop(t_stack *stack)
{
	int	popped_value;

	if (is_empty(stack))
		return (-1);
	popped_value = stack->head->data;
	delete_head(stack);
	return (popped_value);
}

void	free_stack(t_stack *stack)
{
	while (!is_empty(stack))
	{
		delete_head(stack);
	}
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

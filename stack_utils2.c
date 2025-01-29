/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:33:08 by tayki             #+#    #+#             */
/*   Updated: 2025/01/29 18:21:45 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->head == NULL);
}

void	push(t_stack *stack, int data)
{
	if (is_duplicate(stack, data))
	{
		ft_printf("Error: Duplicate value detected (%d)\n", data);
		return ;
	}
	if (insert_before_head(stack, data) == -1)
	{
		ft_printf("Error: Memory allocation failed\n");
	}
}

int	pop(t_stack *stack)
{
	int	popped_value;

	if (is_empty(stack))
	{
		ft_printf("Stack Underflow\n");
		return (-1);
	}
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

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

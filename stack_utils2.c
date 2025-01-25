/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:33:08 by tayki             #+#    #+#             */
/*   Updated: 2025/01/24 19:33:09 by tayki            ###   ########.fr       */
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
		printf("Error: Duplicate value detected (%d)\n", data);
		return ;
	}
	if (insert_before_head(stack, data) == -1)
	{
		printf("Error: Memory allocation failed\n");
	}
}

int	pop(t_stack *stack)
{
	int	popped_value;

	if (is_empty(stack))
	{
		printf("Stack Underflow\n");
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

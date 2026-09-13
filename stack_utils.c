/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:24:13 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/10 13:55:14 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target = NULL;
	new_node->index = -1;
	new_node->is_above_median = -1;
	new_node->is_cheapest = 0;
	new_node->push_cost = -1;
	new_node->rank = -1;
	return (new_node);
}

void	init_stack(t_stack *stack, t_counter *counter)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->element_count = 0;
	stack->counter = counter;
}

int	insert_before_head(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		return (-1);
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->element_count++;
	return (0);
}

int	delete_head(t_stack *stack)
{
	t_node	*temp;

	if (stack->head == NULL)
		return (-1);
	temp = stack->head;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	free(temp);
	stack->element_count--;
	return (0);
}

int	is_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->head;
	while (current != NULL)
	{
		if (current->data == value)
			return (1);
		current = current->next;
	}
	return (0);
}

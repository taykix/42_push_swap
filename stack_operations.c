/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:33:02 by tayki             #+#    #+#             */
/*   Updated: 2025/01/24 19:33:02 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->element_count < 2)
	{
		return ;
	}
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	if (second->next != NULL)
	{
		second->next->prev = first;
	}
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (first->next == NULL)
	{
		stack->tail = first;
	}
}

void	push_to(t_stack *dest, t_stack *src)
{
	int	value;

	if (is_empty(src))
	{
		return ;
	}
	value = pop(src);
	push(dest, value);
	set_indexes(dest);
	set_indexes(src);
}

void	rotate(t_stack *stack)
{
	t_node	*old_head;

	if (stack->element_count < 2)
	{
		return ;
	}
	old_head = stack->head;
	stack->head = old_head->next;
	stack->head->prev = NULL;
	old_head->next = NULL;
	old_head->prev = stack->tail;
	stack->tail->next = old_head;
	stack->tail = old_head;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*old_tail;

	if (stack->element_count < 2)
	{
		return ;
	}
	old_tail = stack->tail;
	stack->tail = old_tail->prev;
	stack->tail->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = stack->head;
	stack->head->prev = old_tail;
	stack->head = old_tail;
}

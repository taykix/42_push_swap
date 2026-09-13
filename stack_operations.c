/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 02:15:34 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/13 02:36:55 by takaraka         ###   ########.fr       */
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
	t_node	*node;

	if (is_empty(src))
		return ;
	node = src->head;
	src->head = node->next;
	if (src->head != NULL)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->element_count--;
	node->prev = NULL;
	node->next = dest->head;
	if (dest->head != NULL)
		dest->head->prev = node;
	else
		dest->tail = node;
	dest->head = node;
	dest->element_count++;
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

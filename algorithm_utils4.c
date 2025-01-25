/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:01:41 by tayki             #+#    #+#             */
/*   Updated: 2025/01/24 23:05:09 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_node_to_top(t_stack *stack, t_node *node_for_top, char stack_name)
{
	t_node	*node;

	node = node_for_top;
	while (node->index != 0)
	{
		if (node->is_above_median)
		{
			rotate(stack);
			printf("r");
		}
		else
		{
			reverse_rotate(stack);
			printf("rr");
		}
		printf("%c\n", stack_name);
		set_indexes(stack);
	}
	if (node->index == 0)
		return (1);
	else
		return (0);
}

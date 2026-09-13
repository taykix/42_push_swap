/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 03:26:06 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/11 03:26:34 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack_a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = stack_a->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

void	set_ranks(t_stack *stack)
{
	t_node	*node;
	t_node	*other;
	int		rank;

	node = stack->head;
	while (node)
	{
		rank = 0;
		other = stack->head;
		while (other)
		{
			if (other->data < node->data)
				rank++;
			other = other->next;
		}
		node->rank = rank;
		node = node->next;
	}
}

static void	choose_adaptive(t_argument *flags)
{
	flags->is_adaptive = 1;
	if (flags->disorder < 0.2)
		flags->is_simple = 1;
	else if (flags->disorder < 0.5)
		flags->is_medium = 1;
	else
		flags->is_complex = 1;
}

void	run_strategy(t_stack *stack_a, t_stack *stack_b, t_argument *flags)
{
	flags->disorder = compute_disorder(stack_a);
	if (!flags->is_simple && !flags->is_medium && !flags->is_complex)
		choose_adaptive(flags);
	if (flags->is_simple)
		flags->name = "simple (cost-based insertion), O(n^2)";
	else if (flags->is_medium)
		flags->name = "medium (sqrt(n) chunk sort), O(n*sqrt(n))";
	else
		flags->name = "complex (LSD radix sort), O(n log n)";
	if (!is_sorted(stack_a))
	{
		if (flags->is_simple)
			sort_simple(stack_a, stack_b);
		else if (flags->is_medium)
			sort_medium(stack_a, stack_b);
		else
			sort_complex(stack_a, stack_b);
	}
	if (flags->is_bench)
		print_bench(flags, stack_a->counter);
}

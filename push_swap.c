/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:58 by tayki             #+#    #+#             */
/*   Updated: 2025/01/25 18:18:19 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;
	int		value;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	i = argc - 1;
	while (i > 0)
	{
		value = validate_and_convert(argv[i]);
		if (!is_duplicate(&stack_a, value))
		{
			push(&stack_a, value);
		}
		else
		{
			ft_printf("Error\n");
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (EXIT_FAILURE);
		}
		i--;
	}
	sort_big(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}

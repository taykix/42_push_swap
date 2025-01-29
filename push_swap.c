/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:58 by tayki             #+#    #+#             */
/*   Updated: 2025/01/29 18:22:42 by tkarakay         ###   ########.fr       */
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

	if (argc < 2 || (argc == 2 && !*argv[1]))
	{
		ft_printf("Error\n");
		free_stacks(&stack_a, &stack_b);
		return (EXIT_FAILURE);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc == 2)
		process_argument(&stack_a, argv[1]);
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			value = validate_and_convert(argv[i]);
			if (!is_duplicate(&stack_a, value))
				push(&stack_a, value);
			else
			{
				ft_printf("Error\n");
				free_stacks(&stack_a, &stack_b);
				return (EXIT_FAILURE);
			}
			i--;
		}
	}
	sort_big(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

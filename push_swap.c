/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:58 by tayki             #+#    #+#             */
/*   Updated: 2025/01/29 19:52:47 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Error\n");
	free_stacks(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

void	process_arguments(int argc, char **argv, t_stack *stack_a)
{
	int	i;
	int	value;

	if (argc == 2)
		process_argument(stack_a, argv[1]);
	else
	{
		i = argc - 1;
		while (i > 0)
		{
			value = validate_and_convert(argv[i]);
			if (!is_duplicate(stack_a, value))
				push(stack_a, value);
			else
			{
				ft_printf("Error\n");
				free_stack(stack_a);
				exit(EXIT_FAILURE);
			}
			i--;
		}
	}
}

int	if_argument_digits(char **argv, int argc)
{
	int	i;
	int	k;

	k = 1;
	while (k < argc)
	{
		i = 0;
		while (argv[k][i] == ' ')
			i++;
		if (argv[k][i] == '\0')
			return (0);
		i = 0;
		while (argv[k][i])
		{
			if (!ft_isdigit(argv[k][i]))
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2 || (argc == 2 && !*argv[1]))
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	if (!if_argument_digits(argv, argc))
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	process_arguments(argc, argv, &stack_a);
	sort_big(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

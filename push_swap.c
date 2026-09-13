/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:52:50 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/12 10:05:56 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_arguments(t_stack *stack_a, char **argv, int argc, int first)
{
	int	i;

	i = argc - 1;
	while (i > first)
	{
		process_argument(stack_a, argv[i]);
		i--;
	}
}

int	if_argument_digits(char **argv, int argc, int flag_count)
{
	int	i;
	int	k;

	k = flag_count + 1;
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
			if (!ft_isdigit(argv[k][i]) && argv[k][i] != ' '
				&& argv[k][i] != '-' && argv[k][i] != '+')
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_counter	counter;
	t_argument	flags;
	int			flag_count;

	if (argc < 2)
		return (EXIT_SUCCESS);
	flag_count = check_arguments(argc, argv, &flags);
	init_counter(&counter);
	init_stack(&stack_a, &counter);
	init_stack(&stack_b, &counter);
	process_arguments(&stack_a, argv, argc, flag_count);
	run_strategy(&stack_a, &stack_b, &flags);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

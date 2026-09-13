/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 04:37:29 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/09 21:08:39 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack_a, char **split)
{
	ft_putendl_fd("Error", 2);
	if (stack_a)
		free_stack(stack_a);
	if (split)
		free_split(split);
	exit(EXIT_FAILURE);
}

int	validate_and_convert(const char *arg, t_stack *stack_a, char **split)
{
	const char	*p;
	int			digits;
	long		value;

	p = arg;
	if (*p == '-' || *p == '+')
		++p;
	if (!ft_isdigit(*p))
		error_exit(stack_a, split);
	while (*p == '0')
		++p;
	digits = 0;
	while (ft_isdigit(*p))
	{
		++digits;
		++p;
	}
	if (*p != '\0' || digits > 10)
		error_exit(stack_a, split);
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX)
		error_exit(stack_a, split);
	return ((int)value);
}

void	process_argument(t_stack *stack_a, const char *arg)
{
	char	**numbers;
	int		i;
	int		value;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		error_exit(stack_a, NULL);
	i = count_split(numbers);
	while (--i >= 0)
	{
		value = validate_and_convert(numbers[i], stack_a, numbers);
		if (is_duplicate(stack_a, value))
			error_exit(stack_a, numbers);
		push(stack_a, value);
	}
	free_split(numbers);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

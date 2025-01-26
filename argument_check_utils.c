/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakay <tkarakay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:54 by tayki             #+#    #+#             */
/*   Updated: 2025/01/26 18:36:20 by tkarakay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_and_convert(const char *arg)
{
	char	*endptr;
	long	value;

	value = ft_atol(arg);
	endptr = (char *)arg;
	while (*endptr == ' ' || (*endptr >= '\t' && *endptr <= '\r'))
		++endptr;
	if (*endptr == '-' || *endptr == '+')
		++endptr;
	while (ft_isdigit(*endptr))
		++endptr;
	if (*endptr != '\0')
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (value < INT_MIN || value > INT_MAX)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return ((int)value);
}

void	process_argument(t_stack *stack_a, const char *arg)
{
	char	**numbers;
	int		i;
	int		value;

	numbers = ft_split(arg, ' ');
	if (!numbers)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	i = count_split(numbers);
	while (--i >= 0)
	{
		value = validate_and_convert(numbers[i]);
		if (!is_duplicate(stack_a, value))
			push(stack_a, value);
		else
		{
			ft_printf("Error\n");
			free_stack(stack_a);
			free_split(numbers);
			exit(EXIT_FAILURE);
		}
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

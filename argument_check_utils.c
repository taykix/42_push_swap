/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayki <tayki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:54 by tayki             #+#    #+#             */
/*   Updated: 2025/01/24 19:38:51 by tayki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_and_convert(const char *arg)
{
	char	*endptr;
	long	value;

	value = strtol(arg, &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "Error: '%s' is not a valid integer\n", arg);
		exit(EXIT_FAILURE);
	}
	if (value < INT_MIN || value > INT_MAX)
	{
		fprintf(stderr, "Error: '%s' is out of range for an integer\n", arg);
		exit(EXIT_FAILURE);
	}
	return ((int)value);
}

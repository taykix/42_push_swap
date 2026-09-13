/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 04:25:17 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/12 19:06:00 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arguments(int argc, char **argv, t_argument *flags)
{
	int	flag_count;

	flag_count = get_flags(argc, argv, flags);
	if (!if_argument_digits(argv, argc, flag_count))
		error_exit(NULL, NULL);
	return (flag_count);
}

t_argument	*init_argument(t_argument *flags)
{
	flags->is_adaptive = 0;
	flags->is_medium = 0;
	flags->is_complex = 0;
	flags->is_bench = 0;
	flags->is_simple = 0;
	flags->disorder = 0.0;
	flags->name = NULL;
	return (flags);
}

void	check_flags(t_argument *flags)
{
	int	sum;

	sum = 0;
	sum += flags->is_adaptive;
	sum += flags->is_complex;
	sum += flags->is_medium;
	sum += flags->is_simple;
	if (sum >= 2)
		error_exit(NULL, NULL);
}

int	get_flags(int argc, char **argv, t_argument *flags)
{
	int	i;

	init_argument(flags);
	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			flags->is_simple = 1;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			flags->is_medium = 1;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			flags->is_complex = 1;
		else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			flags->is_adaptive = 1;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0)
			flags->is_bench = 1;
		else
			error_exit(NULL, NULL);
		i++;
	}
	check_flags(flags);
	return (i - 1);
}

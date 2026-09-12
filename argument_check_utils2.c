#include "push_swap.h"

t_argument	*init_argument(t_argument *flags)
{
	flags->is_adaptive = 0;
	flags->is_medium = 0;
	flags->is_complex = 0;
	flags->is_bench = 0;
	flags->is_simple = 0;

	return (flags);
}

int	check_flags(t_argument flags)
{
	int	sum;

	sum = 0;
	sum += flags.is_adaptive;
	sum += flags.is_complex;
	sum += flags.is_medium;
	sum += flags.is_simple;
	sum += flags.is_bench;
	if (flags.is_bench == 0 && sum >= 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	return (sum + flags.is_bench);
}

int	get_flags(int argc,	char** argv)
{
	t_argument flags;
	int 	i;

	init_argument(&flags);
	i = 0;
	if (argc < 2 || (argc == 2 && !*argv[1]))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0)
			flags.is_simple = 1;
		if (ft_strncmp(argv[i], "--medium", 8) == 0)
			flags.is_medium = 1;
		if (ft_strncmp(argv[i], "--complex", 9) == 0)
			flags.is_complex = 1;
		if (ft_strncmp(argv[i], "--adaptive", 10) == 0)
			flags.is_adaptive = 1;
		if (ft_strncmp(argv[i], "--bench", 7) == 0)
			flags.is_bench = 1;
	}
	return (check_flags(flags));
}
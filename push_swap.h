/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takaraka <takaraka@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:57:58 by takaraka          #+#    #+#             */
/*   Updated: 2026/09/09 09:43:20 by takaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

// Double-linked node structure
typedef struct Node
{
	int			data;
	struct Node	*next;
	struct Node	*prev;
	struct Node	*target;
	int			index;
	int			is_above_median;
	int			is_cheapest;
	int			push_cost;
	int			rank;
}				t_node;

// Operation counters (for --bench), shared by both stacks
typedef struct Counter
{
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}				t_counter;

// Stack structure
typedef struct Stack
{
	t_node		*head;
	t_node		*tail;
	int			element_count;
	t_counter	*counter;
}				t_stack;

typedef struct Argument
{
	int			is_simple;
	int			is_medium;
	int			is_complex;
	int			is_adaptive;
	int			is_bench;
	double		disorder;
	const char	*name;
}	t_argument;

// Function prototypes
t_node			*create_node(int data);
void			init_stack(t_stack *stack, t_counter *counter);
void			init_counter(t_counter *counter);
int				insert_before_head(t_stack *stack, int data);
int				is_empty(t_stack *stack);
void			push(t_stack *stack, int data);
int				pop(t_stack *stack);
void			print_stack(t_stack *stack);
int				validate_and_convert(const char *arg, t_stack *stack_a,
					char **split);
void			error_exit(t_stack *stack_a, char **split);
int				is_duplicate(t_stack *stack, int value);
void			free_stack(t_stack *stack);
void			free_stacks(t_stack *stack_a, t_stack *stack_b);
void			swap(t_stack *stack);
void			push_to(t_stack *dest, t_stack *src);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
int				delete_head(t_stack *stack);
int				is_sorted(t_stack *stack);
void			print_current_state(t_stack *stack_a, t_stack *stack_b);
void			sort_three(t_stack *stack);
void			set_indexes(t_stack *stack);
void			set_target_a(t_stack *stack_a, t_stack *stack_b);
void			set_target_b(t_stack *stack_b, t_stack *stack_a);
t_node			*find_max(t_stack *stack);
t_node			*find_min(t_stack *stack);
void			cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
void			set_cheapest(t_stack *stack);
void			reset_cheapest(t_stack *stack);
t_node			*get_cheapest(t_stack *stack);
void			economic_rotate(t_stack *stack_a, t_stack *stack_b);
int				rotate_node_to_top(t_stack *stack, t_node *node,
					char stack_name);
void			get_stack_ready(t_stack *stack_a, t_stack *stack_b,
					char stack_name);
void			nodes_a_to_b(t_stack *stack_a, t_stack *stack_b);
void			nodes_b_to_a(t_stack *stack_a, t_stack *stack_b);
void			sort_simple(t_stack *stack_a, t_stack *stack_b);
void			sort_medium(t_stack *stack_a, t_stack *stack_b);
void			sort_complex(t_stack *stack_a, t_stack *stack_b);
void			run_strategy(t_stack *stack_a, t_stack *stack_b,
					t_argument *flags);
double			compute_disorder(t_stack *stack_a);
void			set_ranks(t_stack *stack);
void			print_bench(t_argument *flags, t_counter *counter);
void			process_argument(t_stack *stack_a, const char *arg);
void			free_split(char **split);
int				count_split(char **split);
t_argument		*init_argument(t_argument *flags);
int				get_flags(int argc, char **argv, t_argument *flags);
void			check_flags(t_argument *flags);
int				check_arguments(int argc, char **argv, t_argument *flags);
int				if_argument_digits(char **argv, int argc, int flag_count);
void			op_sa(t_stack *stack_a);
void			op_sb(t_stack *stack_b);
void			op_ss(t_stack *stack_a, t_stack *stack_b);
void			op_pa(t_stack *stack_a, t_stack *stack_b);
void			op_pb(t_stack *stack_a, t_stack *stack_b);
void			op_ra(t_stack *stack_a);
void			op_rb(t_stack *stack_b);
void			op_rr(t_stack *stack_a, t_stack *stack_b);
void			op_rra(t_stack *stack_a);
void			op_rrb(t_stack *stack_b);
void			op_rrr(t_stack *stack_a, t_stack *stack_b);

#endif

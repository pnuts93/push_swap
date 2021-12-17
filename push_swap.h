/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:05:39 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/17 17:01:45 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h> //play

typedef struct s_node
{
	int				value;
	int				position;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

t_stack	*init_stack(void);
int		is_same_string(char *s1, char *s2);
void	fill_stack(t_stack *stack, int value);
void	purge_stack(t_stack *stack);
void	purge_bottom(t_stack *stack);
int		check_ifsorted_a(t_stack *stack);
int		check_ifsorted_b(t_stack *stack);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_small_1(t_stack *stack, int c);
void	sort_small_2(t_stack *stack_a, t_stack *stack_b);
void	sort_eq_couple(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack, int c);
void	sort_three(t_stack *stack, int c);
int		stack_size(t_node *bottom);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		get_scheme_a(t_stack *stack_a);
int		get_scheme_b(t_stack *stack_b);
void	halve_n_sort(t_stack *stack_a, t_stack *stack_b);
int		simulate_rr(t_stack *stack_a, t_stack *stack_b, int midpoint);
int		simulate_rrr(t_stack *stack_a, t_stack *stack_b, int midpoint);
void	retrieve_b(t_stack *stack_a, t_stack *stack_b);
void	get_order(t_stack *stack);
void	get_order2(t_stack *stack_a, t_stack *stack_b);
int		do_mvs(t_stack *stack_a, t_stack *stack_b);
void	pa_mute(t_stack *stack_a, t_stack *stack_b);
void	pb_mute(t_stack *stack_b, t_stack *stack_a);
void	sa_mute(t_stack *stack_a);
void	sb_mute(t_stack *stack_b);
void	ss_mute(t_stack *stack_a, t_stack *stack_b);
void	ra_mute(t_stack *stack_a);
void	rb_mute(t_stack *stack_b);
void	rr_mute(t_stack *stack_a, t_stack *stack_b);
void	rra_mute(t_stack *stack_a);
void	rrb_mute(t_stack *stack_b);
void	rrr_mute(t_stack *stack_a, t_stack *stack_b);
int		is_next_valid(void);
void	exhaust_in(void);

void	print_stack(t_stack *stack_a, t_stack *stack_b); //play

# define	MAX_INT 2147483647
# define	MIN_INT -2147483648

#endif

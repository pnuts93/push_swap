/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:28:19 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/26 18:31:18 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack, int c)
{
	if (c == 'a')
	{
		sa(stack);
	}
	else if (c == 'b')
	{
		sb(stack);
	}
}

void	sort_three(t_stack *stack, int c)
{
	int	n_scheme;

	if (c == 'a')
		n_scheme = get_scheme_a(stack);
	else
		n_scheme = get_scheme_b(stack);
	if (n_scheme == 1)
	{
		sa(stack);
		ra(stack);
	}
	else if (n_scheme == 2)
		rra(stack);
	else if (n_scheme == 3)
		sa(stack);
	else if (n_scheme == 4)
		ra(stack);
	else if (n_scheme == 5)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_small_1(t_stack *stack, int c)
{
	if ((c == 'a' && !check_ifsorted_a(stack))
		|| (c == 'b' && !check_ifsorted_b(stack)))
	{
		if (stack_size(stack->bottom) == 2)
			sort_two(stack, c);
		else if (stack_size(stack->bottom) == 3)
			sort_three(stack, c);
	}
}

static void	sort_diff_couple(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	n_scheme;

	if (c == 'a')
		n_scheme = get_scheme_a(stack_a);
	else
		n_scheme = get_scheme_b(stack_b);
	if (n_scheme == 1 || n_scheme == 3 || n_scheme == 5)
		ss(stack_a, stack_b);
	else
	{
		if (c == 'a')
			sb(stack_b);
		else if (c == 'b')
			sa(stack_a);
	}
	if (c == 'a' && !check_ifsorted_a(stack_a))
		sort_three(stack_a, 'a');
	else if (c == 'b' && !check_ifsorted_b(stack_b))
		sort_three(stack_b, 'b');
}

void	sort_small_2(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	if (check_ifsorted_a(stack_a))
		sort_small_1(stack_b, 'b');
	else if (check_ifsorted_b(stack_b))
		sort_small_1(stack_a, 'a');
	else
	{
		len_a = stack_size(stack_a->bottom);
		len_b = stack_size(stack_b->bottom);
		if (len_a == 2 && len_b == 2)
			ss(stack_a, stack_b);
		else if (len_a > len_b)
			sort_diff_couple(stack_a, stack_b, 'a');
		else if (len_a < len_b)
			sort_diff_couple(stack_a, stack_b, 'b');
		else if (len_a == 3 && len_b == 3)
			sort_eq_couple(stack_a, stack_b);
	}
}

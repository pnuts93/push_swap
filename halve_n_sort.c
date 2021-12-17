/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halve_n_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:42:30 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/19 11:28:00 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_value_at(t_stack *stack, int position)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->position == position)
			return (tmp->value);
		tmp = tmp->down;
	}
	return (0);
}

static int	calc_displacements(t_stack *stack_a, int midpoint, int sa_len)
{
	int		rotate;
	int		rev_rotate;
	int		i;
	t_node	*tmp;

	rotate = 0;
	rev_rotate = 0;
	i = 0;
	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->value <= midpoint)
		{
			if (rotate == 0)
				rotate += i;
			if (i > 0)
				rev_rotate = sa_len - i;
		}
		i++;
		tmp = tmp->down;
	}
	if (ft_min(rotate, rev_rotate) == rotate)
		return (rotate);
	else
		return (rev_rotate * -1);
}

static int	push_n(t_stack *stack_a, t_stack *stack_b, int sa_len, int midpoint)
{
	if (stack_a->top->value <= midpoint)
	{
		pb(stack_b, stack_a);
		return (1);
	}
	else if (calc_displacements(stack_a, midpoint, sa_len) < 0)
		rra(stack_a);
	else
		ra(stack_a);
	return (0);
}

static void	analyze_n_push(t_stack *stack_a, t_stack *stack_b, int sa_len)
{
	int	p_left;
	int	midpoint_val;

	get_order(stack_a);
	midpoint_val = get_value_at(stack_a, sa_len / 4) - 1;
	p_left = sa_len / 4;
	while (p_left > 0)
		p_left -= push_n(stack_a, stack_b, sa_len, midpoint_val);
	if (stack_size(stack_a->bottom) > 3)
		analyze_n_push(stack_a, stack_b, stack_size(stack_a->bottom));
}

void	halve_n_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	sa_len;

	sa_len = stack_size(stack_a->bottom);
	if (sa_len <= 3)
	{
		if (stack_size(stack_b->bottom) <= 3)
			sort_small_2(stack_a, stack_b);
		else
			sort_small_1(stack_a, 'a');
	}
	else
		analyze_n_push(stack_a, stack_b, sa_len);
	if (!check_ifsorted_a(stack_a))
		halve_n_sort(stack_a, stack_b);
}

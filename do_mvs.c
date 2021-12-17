/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mvs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 08:47:56 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 11:34:16 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_push(t_stack *stack_a, t_stack *stack_b)
{
	char	c;

	read(0, &c, 1);
	if (c == 'a')
		pa_mute(stack_a, stack_b);
	else if (c == 'b')
		pb_mute(stack_b, stack_a);
	else
		return (-1);
	return (is_next_valid());
}

static int	do_swap(t_stack *stack_a, t_stack *stack_b)
{
	char	c;

	read(0, &c, 1);
	if (c == 'a')
		sa_mute(stack_a);
	else if (c == 'b')
		sb_mute(stack_b);
	else if (c == 's')
		ss_mute(stack_a, stack_b);
	else
		return (-1);
	return (is_next_valid());
}

static int	do_revrotate(t_stack *stack_a, t_stack *stack_b, char c)
{
	if (c == 'a')
		rra_mute(stack_a);
	else if (c == 'b')
		rrb_mute(stack_b);
	else if (c == 'r')
		rrr_mute(stack_a, stack_b);
	else
		return (-1);
	return (1);
}

static int	do_rotate(t_stack *stack_a, t_stack *stack_b)
{
	char	c;
	int		i;

	i = read(0, &c, 1);
	if (c == 'a')
		ra_mute(stack_a);
	else if (c == 'b')
		rb_mute(stack_b);
	else if (c == 'r')
	{
		i = read(0, &c, 1);
		if (c == '\n' || i == 0)
		{
			rr_mute(stack_a, stack_b);
			return (i);
		}
		else if (do_revrotate(stack_a, stack_b, c) == -1)
			return (-1);
	}
	else
		return (-1);
	return (is_next_valid());
}

int	do_mvs(t_stack *stack_a, t_stack *stack_b)
{
	char	c;
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(0, &c, 1);
		if (i == 0)
			return (1);
		if (c == 'p')
			i = do_push(stack_a, stack_b);
		else if (c == 's')
			i = do_swap(stack_a, stack_b);
		else if (c == 'r')
			i = do_rotate(stack_a, stack_b);
		if ((c != 'p' && c != 's' && c != 'r') || i == -1)
		{
			exhaust_in();
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

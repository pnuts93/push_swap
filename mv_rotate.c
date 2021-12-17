/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:22:31 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 10:24:51 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	stack->top->up = stack->bottom;
	stack->bottom = stack->top;
	stack->top = stack->bottom->down;
	stack->bottom->up->down = stack->bottom;
	stack->bottom->down = NULL;
	stack->top->up = NULL;
}

void	ra(t_stack *stack_a)
{
	if (stack_size(stack_a->bottom) > 1)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a->bottom) > 1 && stack_size(stack_b->bottom) > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}

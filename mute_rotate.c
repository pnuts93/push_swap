/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mute_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:23:04 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 10:24:44 by pnuti            ###   ########.fr       */
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

void	ra_mute(t_stack *stack_a)
{
	if (stack_size(stack_a->bottom) > 1)
		rotate(stack_a);
}

void	rb_mute(t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1)
		rotate(stack_b);
}

void	rr_mute(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a->bottom) > 1 && stack_size(stack_b->bottom) > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

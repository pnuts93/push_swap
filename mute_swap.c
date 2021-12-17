/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mute_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:49:30 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 10:22:33 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	stack->top = stack->top->down;
	if (stack->top->down)
	{
		stack->top->up->down = stack->top->down;
		stack->top->down = stack->top->up;
		stack->top->up->down->up = stack->top->up;
		stack->top->up = NULL;
		stack->top->down->up = stack->top;
	}
	else
	{
		stack->bottom = stack->bottom->up;
		stack->bottom->up = stack->top;
		stack->top->down = stack->bottom;
		stack->top->up = NULL;
		stack->bottom->down = NULL;
	}
}

void	sa_mute(t_stack *stack_a)
{
	if (stack_size(stack_a->bottom) > 1)
		swap(stack_a);
}

void	sb_mute(t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1)
		swap(stack_b);
}

void	ss_mute(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1 && stack_size(stack_a->bottom) > 1)
	{
		swap(stack_a);
		swap(stack_b);
	}
}

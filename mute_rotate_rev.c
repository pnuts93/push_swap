/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mute_rotate_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:59:34 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 10:17:16 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_stack *stack)
{
	stack->bottom->down = stack->top;
	stack->top = stack->bottom;
	stack->bottom = stack->top->up;
	stack->top->down->up = stack->top;
	stack->top->up = NULL;
	stack->bottom->down = NULL;
}

void	rra_mute(t_stack *stack_a)
{
	if (stack_size(stack_a->bottom) > 1)
		rotate_reverse(stack_a);
}

void	rrb_mute(t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1)
		rotate_reverse(stack_b);
}

void	rrr_mute(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a->bottom) > 1 && stack_size(stack_b->bottom) > 1)
	{
		rotate_reverse(stack_a);
		rotate_reverse(stack_b);
	}
}

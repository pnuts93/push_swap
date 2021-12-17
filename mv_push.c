/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:37:36 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 09:49:06 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_dest, t_stack *stack_src)
{
	if (stack_src->top->down)
	{
		stack_src->top = stack_src->top->down;
		stack_src->top->up->down = stack_dest->top;
		if (!stack_dest->top)
		{
			stack_dest->top = stack_src->top->up;
			stack_dest->bottom = stack_src->top->up;
		}
		else
		{
			stack_dest->top->up = stack_src->top->up;
			stack_dest->top = stack_dest->top->up;
		}
		stack_src->top->up = NULL;
	}
	else
	{
		stack_src->bottom->down = stack_dest->top;
		stack_dest->top = stack_src->top;
		stack_dest->top->down->up = stack_dest->top;
		stack_src->top = NULL;
		stack_src->bottom = NULL;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 0)
	{
		push(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_size(stack_a->bottom) > 0)
	{
		push(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}

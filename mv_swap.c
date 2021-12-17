/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:17:42 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 09:52:18 by pnuti            ###   ########.fr       */
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

void	sa(t_stack *stack_a)
{
	if (stack_size(stack_a->bottom) > 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_b->bottom) > 1 && stack_size(stack_a->bottom) > 1)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}

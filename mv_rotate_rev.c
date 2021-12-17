/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:39:55 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 09:59:44 by pnuti            ###   ########.fr       */
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

void	rra(t_stack *stack_a)
{
	rotate_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	rotate_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:21:29 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/30 10:28:58 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_next(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		s_len;
	t_node	*tmp;

	i = 0;
	tmp = stack_b->top;
	s_len = stack_size(stack_b->bottom);
	while ((tmp->position != stack_a->top->position - 1) && tmp)
	{
		tmp = tmp->down;
		i++;
	}
	if (i > (s_len / 4) + 1)
		return (i - s_len);
	else
		return (i);
}

void	retrieve_b(t_stack *stack_a, t_stack *stack_b)
{
	int	shift;
	int	swap_check;

	shift = get_next(stack_a, stack_b);
	swap_check = 0;
	while (shift != 0)
	{
		if (shift > 0)
		{
			if (shift == 1)
				sb(stack_b);
			else
				rb(stack_b);
			shift--;
		}
		else
		{
			rrb(stack_b);
			shift++;
		}
	}
	pa(stack_a, stack_b);
	if (swap_check == 1)
		sa(stack_a);
}

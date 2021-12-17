/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:59:42 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/15 17:54:03 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_pos(t_stack *stack)
{
	int		max_v;
	int		max_p;
	t_node	*tmp;

	tmp = stack->bottom;
	max_v = tmp->value;
	tmp = tmp->up;
	while (tmp)
	{
		if (tmp->value > max_v)
		{
			max_v = tmp->value;
			max_p = tmp->position;
		}
		tmp = tmp->up;
	}
	return (max_p);
}

void	get_order(t_stack *stack)
{
	int		count;
	t_node	*tmp;
	t_node	*comp;

	tmp = stack->bottom;
	while (tmp)
	{
		count = 0;
		comp = stack->bottom;
		while (comp)
		{
			if (tmp->value > comp->value)
				count++;
			comp = comp->up;
		}
		tmp->position = count;
		tmp = tmp->up;
	}
}

void	get_order2(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	int		max_b;
	t_node	*tmp;
	t_node	*comp;

	get_order(stack_b);
	max_b = max_pos(stack_b);
	tmp = stack_a->bottom;
	while (tmp)
	{
		count = max_b + 1;
		comp = stack_a->bottom;
		while (comp)
		{
			if (tmp->value > comp->value)
				count++;
			comp = comp->up;
		}
		tmp->position = count;
		tmp = tmp->up;
	}
}

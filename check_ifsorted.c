/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ifsorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:12:28 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/09 15:05:05 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ifsorted_a(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->down)
	{
		if (tmp->value > tmp->down->value)
			return (0);
		tmp = tmp->down;
	}
	return (1);
}

int	check_ifsorted_b(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->down)
	{
		if (tmp->value < tmp->down->value)
			return (0);
		tmp = tmp->down;
	}
	return (1);
}

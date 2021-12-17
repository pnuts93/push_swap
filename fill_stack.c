/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:13:59 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/18 16:53:10 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*init_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->up = NULL;
	node->down = NULL;
	node->position = 0;
	return (node);
}

void	fill_stack(t_stack *stack, int value)
{
	t_node	*node;

	node = init_node(value);
	if (stack->bottom)
	{
		stack->bottom->down = node;
		node->up = stack->bottom;
		stack->bottom = node;
	}
	else
	{
		stack->bottom = node;
		stack->top = node;
	}
}

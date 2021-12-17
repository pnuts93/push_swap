/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge_bottom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:00:35 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/08 14:03:10 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	purge_bottom(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->bottom->down && !stack->bottom->up)
	{
		tmp = stack->bottom;
		stack->bottom = NULL;
		stack->top = NULL;
		free(tmp);
		return ;
	}
	tmp = stack->bottom;
	stack->bottom = tmp->up;
	stack->bottom->down = NULL;
	free(tmp);
}

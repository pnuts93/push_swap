/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:36:22 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/08 14:04:05 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	purge_stack(t_stack *stack)
{
	while (stack->bottom)
		purge_bottom(stack);
	stack->bottom = NULL;
	stack->top = NULL;
	free(stack);
}

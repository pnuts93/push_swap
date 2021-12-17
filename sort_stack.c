/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:44:03 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/18 18:17:26 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	halve_n_sort(stack_a, stack_b);
	get_order2(stack_a, stack_b);
	while (stack_b->top)
		retrieve_b(stack_a, stack_b);
}

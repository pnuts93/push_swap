/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_eq_couple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:14:36 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/18 16:55:44 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_same_scheme(t_stack *stack_a, t_stack *stack_b, int n_scheme)
{
	if (n_scheme == 1)
	{
		ss(stack_a, stack_b);
		rr(stack_a, stack_b);
	}
	else if (n_scheme == 2)
		rrr(stack_a, stack_b);
	else if (n_scheme == 3)
		ss(stack_a, stack_b);
	else if (n_scheme == 4)
		rr(stack_a, stack_b);
	else if (n_scheme == 5)
	{
		ss(stack_a, stack_b);
		rrr(stack_a, stack_b);
	}
}

void	sort_eq_couple(t_stack *stack_a, t_stack *stack_b)
{
	int	scheme_a;
	int	scheme_b;

	scheme_a = get_scheme_a(stack_a);
	scheme_b = get_scheme_b(stack_b);
	if (scheme_a == scheme_b)
	{
		sort_same_scheme(stack_a, stack_b, scheme_a);
		return ;
	}
	else if ((scheme_a == 1 || scheme_a == 3 || scheme_a == 5)
		&& (scheme_b == 1 || scheme_b == 3 || scheme_b == 5))
		ss(stack_a, stack_b);
	else if ((scheme_a == 2 || scheme_a == 5)
		&& (scheme_b == 2 || scheme_b == 5))
		rrr(stack_a, stack_b);
	else if ((scheme_a == 1 || scheme_a == 4)
		&& (scheme_b == 1 || scheme_b == 4))
		rr(stack_a, stack_b);
	sort_small_1(stack_a, 'a');
	sort_small_1(stack_b, 'b');
}

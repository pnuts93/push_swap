/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scheme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:50:09 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/15 10:51:25 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_scheme_a(t_stack *stack_a)
{
	int	n_scheme;
	int	n1;
	int	n2;
	int	n3;

	n1 = stack_a->top->value;
	n2 = stack_a->top->down->value;
	n3 = stack_a->top->down->down->value;
	if (n1 < n2 && n1 < n3)
		n_scheme = 1;
	else if (n1 < n2 && n1 > n3)
		n_scheme = 2;
	else if (n1 > n2 && n1 < n3)
		n_scheme = 3;
	else if (n3 > n2 && n3 < n1)
		n_scheme = 4;
	else
		n_scheme = 5;
	return (n_scheme);
}

int	get_scheme_b(t_stack *stack_b)
{
	int	n_scheme;
	int	n1;
	int	n2;
	int	n3;

	n1 = stack_b->top->value;
	n2 = stack_b->top->down->value;
	n3 = stack_b->top->down->down->value;
	if (n3 > n2 && n3 < n1)
		n_scheme = 1;
	else if (n1 > n2 && n1 < n3)
		n_scheme = 2;
	else if (n1 < n2 && n1 > n3)
		n_scheme = 3;
	else if (n3 < n2 && n1 < n2)
		n_scheme = 4;
	else
		n_scheme = 5;
	return (n_scheme);
}

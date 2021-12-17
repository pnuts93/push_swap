/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_print_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:48:54 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/17 17:54:12 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *put_stack_a(t_node *top_a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%11d . %-11c\n", top_a->value, ' ');
		top_a = top_a->down;
		i++;
	}
	return (top_a);
}

t_node *put_stack_b(t_node *top_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%11c . %-11d\n", ' ', top_b->value);
		top_b = top_b->down;
		i++;
	}
	return (top_b);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		diff;
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = stack_a->top;
	tmp_b = stack_b->top;
	diff = stack_size(stack_a->bottom) - stack_size(stack_b->bottom);
	if (diff > 0)
		tmp_a = put_stack_a(tmp_a, diff);
	else
		tmp_b = put_stack_b(tmp_b, diff * -1);
	while (tmp_a != NULL && tmp_b != NULL)
	{
		printf("%11d . %-11d\n", tmp_a->value, tmp_b->value);
		tmp_a = tmp_a->down;
		tmp_b = tmp_b->down;
	}
	printf("- - - - - - - - - - - - -\n");
	printf("%11s . %-11s\n", "stack A", "stack B");
}

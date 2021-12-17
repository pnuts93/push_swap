/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:25:28 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/30 09:17:50 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (is_same_string(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	add_if_int(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > MAX_INT || num < MIN_INT)
			return (1);
		fill_stack(stack, num);
		i++;
	}
	return (0);
}

static int	fill_and_check(int argc, char **argv, t_stack *stack)
{
	if (is_not_digit(argc, argv) || is_duplicate(argc, argv)
		|| add_if_int(argc, argv, stack))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	if (fill_and_check(argc, argv, stack_a) || check_ifsorted_a(stack_a))
		purge_stack(stack_a);
	else if (stack_size(stack_a->bottom) <= 3)
	{
		if (stack_size(stack_a->bottom) == 2)
			sort_two(stack_a, 'a');
		else if (stack_size(stack_a->bottom) == 3)
			sort_three(stack_a, 'a');
		purge_stack(stack_a);
	}
	else
	{
		stack_b = init_stack();
		sort_stack(stack_a, stack_b);
		purge_stack(stack_a);
		purge_stack(stack_b);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:35:49 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/18 16:35:39 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_next_valid(void)
{
	int		i;
	char	c;

	i = read(0, &c, 1);
	if (i == 0)
		return (0);
	else if (c == '\n')
		return (1);
	else
		return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exhaust_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:51:42 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/21 11:12:49 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exhaust_in(void)
{
	int		i;
	char	c;

	i = read(0, &c, 1);
	while (i != 0 && c != '\n')
		i = read(0, &c, 1);
}
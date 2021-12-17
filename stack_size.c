/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:41:23 by pnuti             #+#    #+#             */
/*   Updated: 2021/07/09 14:41:47 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *bottom)
{
	if (!bottom)
		return (0);
	if (!bottom->up)
		return (1);
	return (1 + stack_size(bottom->up));
}

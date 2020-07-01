/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:18:10 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 14:05:41 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	swap_b(t_stacks *stack)
{
	int	tmp;

	if (stack->len_b >= 0)
	{
		if (stack->len_b <= 1)
			return (1);
		tmp = stack->array_b[1];
		stack->array_b[1] = stack->array_b[0];
		stack->array_b[0] = tmp;
		return (1);
	}
	return (0);
}

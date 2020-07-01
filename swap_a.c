/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:05:47 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 14:05:29 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		swap_a(t_stacks *stack)
{
	int tmp;

	if (stack->len_a >= 0)
	{
		if (stack->len_a <= 1)
			return (1);
		tmp	= stack->array_a[1];
		stack->array_a[1] = stack->array_a[0];
		stack->array_a[0] = tmp;
		return (1);
	}
	return (0);
}

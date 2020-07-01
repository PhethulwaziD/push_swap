/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:17:38 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 14:08:09 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rev_rot_a(t_stacks *stack)
{
	int i;
	int tmp;

	i = stack->len_a;
	if (stack->len_a >= 0)
	{
		if (stack->len_a <= 1)
			return (1);
		tmp = stack->array_a[stack->len_a - 1];
		while (i >= 0)
		{
			i--;
			stack->array_a[i + 1] = stack->array_a[i];
		}
		stack->array_a[0] = tmp;
		return (1);
	}
	return (0);
}

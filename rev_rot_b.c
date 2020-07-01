/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:41:13 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 14:09:20 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rev_rot_b(t_stacks *stack)
{
	int i;
	int tmp;

	i = stack->len_b;
	if (stack->len_b > 1)
	{
		if (stack->len_b <= 1)
			return (1);
		tmp = stack->array_b[stack->len_b - 1];
		while (i >= 0)
		{
			i--;
			stack->array_b[i + 1] = stack->array_b[i];
		}
		stack->array_b[0] = tmp;
		return (1);
	}
	return (0);
}

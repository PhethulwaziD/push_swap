/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:22:41 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 14:02:10 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	rotate_a(t_stacks *stack)
{
	int	i;
	int tmp;

	i = 0;
	if (stack->len_a >= 0)
	{
		if (stack->len_a <= 1)
			return (1);
		tmp  = stack->array_a[0];
		while (i < stack->len_a)
		{
			stack->array_a[i] = stack->array_a[i + 1];
			i++;
		}
		stack->array_a[i - 1] = tmp;
		return (1);
	}
	return (0);
}

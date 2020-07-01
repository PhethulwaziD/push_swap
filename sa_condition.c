/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:52:57 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/25 14:56:04 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		condition_one(t_stacks *stack)
{
	int			i;

	if (*stack->top_a > stack->array_a[1] )
	{
		i = 2;
		while (i < stack->len_a)
		{
			if (stack->array_a[i] > stack->array_a[1]\
					&& stack->array_a[i] < *stack->top_a)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int		condition_two(t_stacks *stack)
{
	if (*stack->top_a == biggest(stack) && stack->array_a[1] != smallest(stack))
		return (1);
	return (0);
}

int				sa_condition(t_stacks *stack)
{
	if (stack->len_b > 0 && *stack->top_b < *stack->top_a)
		if (condition_one(stack) == 1)
			return (2);
	if (condition_two(stack) == 1)
		return (1);
	if (stack->len_b == 0 && condition_one(stack) == 1)
		return (3);
	return (0);
}

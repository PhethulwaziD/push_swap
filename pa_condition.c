/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:54:53 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/25 17:36:36 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			condition_one(t_stacks *stack)
{
	int				i;

	i = 1;
	if (*stack->top_a > *stack->top_b)
	{
		while (i < stack->len_a)
		{
			if (stack->array_a[i] < *stack->top_a\
				&& stack->array_a[i] > *stack->top_b)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int			condition_two(t_stacks *stack)
{
	int				i;

	i = 1;
	if (*stack->top_a != biggest(stack) || *stack->top_a != smallest(stack))
	{
		while (i < stack->len_a)
		{
			if (*stack->top_a < stack->array_a[i] && *stack->top_a > stack->array_a[i - 1])
				return (1);
			i++;
		}
	}
	return (0);
}

int					pa_condition(t_stacks *stack)
{
	if (stack->len_b > 0)
		if (condition_one(stack) == 1 && condition_two(stack) == 0)
			return (1);
	return (0);
}

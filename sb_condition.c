/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:55:07 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/21 17:28:34 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int best_value_a (t_stacks *stack, int val)
{
	int i;

	i = 1;
	if (stack->len_a > 2)
	{
		while (i < stack->len_a)
		{
			if (stack->array_a[i] > val &&  stack->array_a[i - 1] < val)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int best_value_b (t_stacks *stack, int val)
{
	int i;
	int lst_a;

	lst_a = stack->len_a - 1;
	i = 0;
	while (i < stack->len_b)
	{
		if (stack->array_b[i] != val)
			if (stack->array_b[i] < *stack->top_a && stack->array_b[i] > stack->array_a[lst_a]\
				&& stack->array_b[i] > val)
				return (0);
		i++;
	}
	return (1);
}

static int condition_zero(t_stacks *stack)
{
	int lst_a;

	lst_a = stack->len_a - 1;
	if (stack->len_b > 1)
	{
		if (stack->array_b[1] < *stack->top_a && stack->array_b[1] > stack->array_a[lst_a])
		{	
			if (best_value_a(stack, stack->array_b[1]) == 1 && best_value_b(stack, stack->array_b[1]) == 1)
				return (1);
		}
	}
	return (0);
}

int sb_condition(t_stacks *stack)
{
	if (((ra_condition(stack) != 0 || rra_condition(stack) != 0)\
		&& sa_condition(stack) != 1) || pa_condition(stack) != 0)
	{
		if (condition_zero(stack) == 1)
			return (1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:03:17 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/20 14:27:40 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			biggest_stack_a(t_stacks *stack)
{
	int		i;
	int		big;

	i = 0;
	if (stack->len_a > 0)
	{
		big = stack->array_a[i];
		while (i < stack->len_a)
		{
			if (stack->array_a[i] > big)
				big = stack->array_a[i];
		i++;
		}
	}
	return (big);
}

int			biggest_stack_b(t_stacks *stack)
{
	int		i;
	int		big;

	i = 0;
	if (stack->len_b > 0)
	{
		big = stack->array_b[i];
		while (i < stack->len_b)
		{
			if (stack->array_b[i] > big)
				big = stack->array_b[i];
		i++;
		}
	}
	return (big);
}

int			biggest(t_stacks *stack)
{
	if (stack->len_b > 0 && stack->len_a > 0)
	{
		if (biggest_stack_a(stack) > biggest_stack_b(stack))
			return (biggest_stack_a(stack));
		return (biggest_stack_b(stack));
	}
	if (stack->len_a > 0 && stack->len_b == 0)
		return (biggest_stack_a(stack));
	return (biggest_stack_b(stack));
}

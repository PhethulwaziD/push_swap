/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:31:24 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/21 17:27:46 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		half_length(t_stacks *stack)
{
	if ((stack->len_a % 2) == 0)
		return (stack->len_a / 2);
	return ((stack->len_a / 2) + 1);
}

static int		position(t_stacks *stack)
{
	int			i;
	int			lst;

	i = 0;
	lst = stack->len_a - 1;
	if (*stack->top_a > stack->array_a[lst])
	{
		while (i < stack->len_a && stack->array_a[i] > stack->array_a[lst])
			i++;
		if (i > half_length(stack))
			return (0);
		else
			return (1);
	}
	return (0);
}

static int		rotate_stack(t_stacks *stack)
{
	int			i;

	i = 0;
	while (i++ < half_length(stack))
		if (stack->array_a[i] < stack->array_a[i - 1])
			if (position(stack) == 1)
				return (1);
	return (0);
}

static int		condition_one(t_stacks *stack)
{
	int			i;
	int			lst;

	i = 0;
	lst = stack->len_a - 1;
	if (*stack->top_a > stack->array_a[lst])
	{
		while (i++ < stack->len_a)
		{
			if (stack->array_a[i] < *stack->top_a\
			   	&& stack->array_a[i] > stack->array_a[lst])
				return (0);
		}
		if (position(stack) == 1)
			return (1);
	}
	return (0);
}

static int		condition_two(t_stacks *stack)
{
	int			i;
	int			lst;

	i = 0;
	lst = stack->len_a - 1;
	if (*stack->top_a > stack->array_a[lst])
	{
		while (i < stack->len_b)
		{
			if (stack->array_b[i] > stack->array_a[lst])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int		rot_stack(t_stacks *stack)
{
	int			i;

	i = 0;
	if (stack->len_b > 0)
	{
		while (i++ < stack->len_a)
		{
			if (*stack->top_b > stack->array_a[i - 1]\
				&& *stack->top_b < stack->array_a[i])
				return (1);
		}
	}
	return (0);
}

int				ra_condition(t_stacks *stack)
{
	if (pa_condition(stack) == 0)
	{	
		if (stack->len_b == 0)
			if (condition_one(stack) == 1)
				return (1);
		if (stack->len_b > 0)
			if (condition_one(stack) == 1)
				if (condition_two(stack) == 1)
					return (2);
		if (rotate_stack(stack) == 1 && pb_condition(stack) == 0 && pa_condition(stack) == 0)
			return (3);
		if (rot_stack(stack) == 1 && pb_condition(stack) == 0 && pa_condition(stack) == 0)
			return (4);
	}
	return (0);
}

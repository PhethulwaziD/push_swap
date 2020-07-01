/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:55:07 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/21 17:28:34 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				half_length(t_stacks *stack)
{
	if ((stack->len_a % 2) >= 1 )
		return ((stack->len_a / 2) + 1);
	return (stack->len_a / 2);
}

static int				condition_one(t_stacks *stack)
{
	int			i;
	int			lst;

	i = 0;
	lst = stack->len_a - 1;
	if (stack->array_a[lst] < *stack->top_a)
	{	
		while (i < stack->len_a)
		{
			if (stack->array_a[i] != *stack->top_a\
				   	&& stack->array_a[i] < stack->array_a[lst])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int				condition_two(t_stacks *stack)
{
	int					i;
	int					lst;

	i = 0;
	lst = stack->len_a - 1;
	if (stack->array_a[lst] > *stack->top_a)
	{
		while (i < stack->len_b)
		{
			if (stack->array_a[i] > stack->array_a[lst])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int				rev_rot_stack(t_stacks *stack)
{
	int					i;
	int					len;

	i = stack->len_a;
	len = stack->len_a - half_length(stack);
	while (i-- > len)
		if (stack->array_a[i] < stack->array_a[i - 1])
			return (1);
	return (0);
}

int						rra_condition(t_stacks *stack)
{
	if (stack->len_b == 0)
		if (condition_one(stack) == 1 && pb_condition(stack) == 0)
			return (1);
	if (stack->len_b > 0)
		if (condition_two(stack) == 1 && condition_one(stack) == 1)
			return (2);
	if (rev_rot_stack(stack) == 1 && pb_condition(stack) == 0 && pa_condition(stack) == 0)
		return (3);
	return (0);
}

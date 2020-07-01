/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:25:07 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/20 14:28:09 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				small_stack_a(t_stacks *stack)
{
	int			i;
	int			small;

	i = 0;
	if (stack->len_a > 0)
	{
		small = stack->array_a[i];
		while (i <stack->len_a)
		{
			if (stack->array_a[i] < small)
				small = stack->array_a[i];
			i++;
		}
	}
	return (small);
}

static int			small_stack_b(t_stacks *stack)
{
	int			i;
	int			small;

	i = 0;
	if (stack->len_b > 0)
	{
		small = stack->array_b[i];
		while (i < stack->len_b)
		{
			if (stack->array_b[i] < small)
				small = stack->array_b[i];
			i++;
		}
	}
	return (small);
}

int					smallest(t_stacks *stack)
{
	if (stack->len_a > 0 && stack->len_b > 0)
	{
		if (small_stack_a(stack) < small_stack_b(stack))
			return (small_stack_a(stack));
		else
			return (small_stack_b(stack));
	}
	else if (stack->len_a > 0 && stack->len_b == 0)
		return (small_stack_a(stack));
	return (small_stack_b(stack));
}


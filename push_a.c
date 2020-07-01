/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:00:19 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/20 15:44:05 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void increase_a(t_stacks *stack)
{
	int i;

	i = stack->len_a;
	while (i >= 0)
	{
		stack->array_a[i + 1] = stack->array_a[i];
		i--;
	}
}

static void decrease_b(t_stacks *stack)
{
	int		i;

	i = 0;
	while (i < stack->len_b)
	{
		stack->array_b[i] = stack->array_b[i + 1];
		i++;
	}
}

int		push_a(t_stacks *stack)
{
	if (stack->len_b >= 0)
	{
		if (stack->len_b == 0)
			return (1);
		increase_a(stack);
		stack->array_a[0] = stack->array_b[0];
		decrease_b(stack);
		if (stack->len_b == 0)
			*stack->top_b = 0;
		stack->len_b--;
		stack->len_a++;
		return (1);
	}
	return (0);
}

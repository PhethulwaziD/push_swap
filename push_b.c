/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:26:35 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/20 15:43:55 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void decrease_a(t_stacks *stack)
{
	int i;

	i = 0;
	while (i < stack->len_a)
	{
		stack->array_a[i] = stack->array_a[i + 1];
		i++;
	}
}

static void increase_b(t_stacks *stack)
{
	int i;

	i = stack->len_b;
	while (i >= 0)
	{
		stack->array_b[i + 1] = stack->array_b[i];
		i--;
	}
}

int		push_b(t_stacks *stack)
{
	if (stack->len_a >= 0)
	{
		if (stack->len_a == 0)
			return (1);
		increase_b(stack);
		stack->array_b[0] = stack->array_a[0];
		decrease_a(stack);
		stack->len_b++;
		stack->len_a--;
		if (stack->len_a == 0)
			*stack->top_a = 0;
		return (1);
	}
	return (0);
}

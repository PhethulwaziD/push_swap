/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:33:06 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/20 18:44:07 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			condition_one(t_stacks *stack)
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

int					pb_condition(t_stacks *stack)
{
	if (condition_one(stack) == 1 && pa_condition(stack) == 0)
		return (1);
	return (0);
}

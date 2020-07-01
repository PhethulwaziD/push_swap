/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:35:43 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 14:01:27 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_b(t_stacks *stack)
{
	int	i;
	int tmp;

	i = 0;
	if (stack->len_b >= 0)
	{
		if (stack->len_b <= 1)
			return (1);
		tmp  = stack->array_b[0];
		while (i < stack->len_b)
		{
			stack->array_b[i] = stack->array_b[i + 1];
			i++;
		}
		stack->array_b[i - 1] = tmp;
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:47:00 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 11:26:14 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort(t_stacks *stack)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (stack->len_b != 0)
		 return (0);
	if (stack->len_a > 1)
	{
		while (i < stack->len_a)
		{	
			j = i + 1;
			while (j < stack->len_a)
			{
				if (stack->array_a[i] > stack->array_a[j])
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

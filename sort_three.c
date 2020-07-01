/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:15:58 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/20 16:34:00 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_stacks *stack)
{
	int		big;

	big = biggest(stack);
	while (check_sort(stack) == 0)
	{
		if (*stack->top_a == big)
		{
			ft_putendl("ra");
			rotate_a(stack);
		}
		else if (stack->array_a[1] == big)
		{
			rev_rot_a(stack);
			ft_putendl("rra");
		}
		else
		{
			ft_putendl("sa");
			swap_a(stack);
		}
	}
}

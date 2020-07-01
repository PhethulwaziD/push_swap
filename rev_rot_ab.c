/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:46:07 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 17:09:30 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rev_rot_ab(t_stacks *stack)
{
	if (stack->len_a >= 0 && stack->len_b >= 0)
	{
		if (stack->len_a <= 1 || stack->len_b <= 1)
			return (1);
		rev_rot_a(stack);
		rev_rot_b(stack);
		return (1);
	}
	return (0);
}

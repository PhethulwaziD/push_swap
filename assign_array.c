/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:26:14 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/16 16:58:57 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			assign_array(char **av, int ac, t_stacks *stack)
{
	int		i;
	int		j;

	i = 0;	
	j = 0;
	stack->top_a = &stack->array_a[0];
	stack->top_b = &stack->array_b[0];
	stack->len_a = 0;
	stack->len_b = 0;
	while (i++ < ac)
	{
		if (ft_isint(av[ac]) == 0)
			return (0);
		stack->array_a[j] = ft_atoi(av[i]);
		j++;
	}
	stack->len_a = j;
	i = 0;
	while (i < stack->len_a)
	{
		if (stack->array_a[i] > MAX_INT || stack->array_a[i] < MIN_INT)
			return (0);
		i++;
	}
	stack->len_b = 0;
	if (check_repeat(stack) == 0)
		return (0);
	return (1);
}

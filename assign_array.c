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

int assign_array(char **av, int ac, t_stacks *stack)
{
    int             i;
    int             j;
    long long 		val;

    i = 0;
    j = 0;
    val = 0;
    stack->top_a = &stack->array_a[0];
    stack->top_b = &stack->array_b[0];
    stack->len_a = 0;
    stack->len_b = 0;
    while (i++ < ac)
    {
        if (ft_isint(av[i]) == 0)
                return (0);
        val = ft_atoi(av[i]);
        if (val > INT_MAX || val < INT_MIN)
            return (0);
        stack->array_a[j] = val;
        j++;
    }
    stack->len_a = j;
    stack->len_b = 0;
    if (check_repeat(stack) == 0)
            return (0);
    return (1);
}

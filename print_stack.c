/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:24:39 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/25 14:54:54 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack_a (t_stacks *stack)
{
	int i;

	i = 0;
	ft_putstr("a | ");
	while (i < stack->len_a)
	{
		ft_putnbr(stack->array_a[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl(" ");
}

static void print_stack_b(t_stacks *stack)
{
	int 	j;

	j = 0;
	ft_putstr("b | ");
	while (j < stack->len_b)
	{
		ft_putnbr(stack->array_b[j]);
		ft_putstr(" ");
		j++;
	}
	ft_putendl(" ");
	ft_putendl(" ");
}

void		print_stack(t_stacks *stack)
{

	if (stack->len_a > 0 || stack->len_b > 0)
	{
		print_stack_a(stack);
		print_stack_b(stack);
	}
}

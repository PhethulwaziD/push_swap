/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:20:54 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/18 14:13:09 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stacks		stack;
	if (ac-- > 1)
	{
		stack.array_a = malloc(sizeof(int) * (ac));
		stack.array_b = malloc(sizeof(int) * (ac));	
		if (assign_array(av, ac, &stack) != 0)
		{
			if (check_sort(&stack) == 1)
				exit (0);
			if (stack.len_a > 1 && stack.len_a <= 3)
				sort_three(&stack);
			else if (stack.len_a > 3 && stack.len_a <= 5)
				sort_five(&stack);
			else if (stack.len_a > 5)
				sort_hundred(&stack);
			else
				exit(0);
		}
		else if (assign_array(av, ac, &stack) == 0)
			ft_putendl("Error");
		free(stack.array_a);
		free(stack.array_b);
	}
	return (0);
}

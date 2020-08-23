/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:28:47 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/18 14:11:54 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void valid_moves(t_stacks *stack)
{
	ft_putstr("sb  :");
	ft_putendl(ft_itoa(sb_condition(stack))) ;
	ft_putstr("rb  :");
	ft_putendl(ft_itoa(rb_condition(stack))) ;
	ft_putstr("rrb :");
	ft_putendl(ft_itoa(rrb_condition(stack)));
	ft_putstr("sa  :");
	ft_putendl(ft_itoa(sa_condition(stack))) ;
	ft_putstr("ra  :");
	ft_putendl(ft_itoa(ra_condition(stack))) ;
	ft_putstr("rra :");
	ft_putendl(ft_itoa(rra_condition(stack)));
	ft_putstr("pb  :");
	ft_putendl(ft_itoa(pb_condition(stack))) ;
	ft_putstr("pa  :");
	ft_putendl(ft_itoa(pa_condition(stack))) ;
	print_stack(stack);
}

static int			swap(char	*instruct, t_stacks *stack)
{
	valid_moves(stack);
	if (ft_strequ("sa", instruct) == 1)
		return (swap_a(stack));
	else if (ft_strequ("sb", instruct) == 1)
		return (swap_b(stack));
	else if (ft_strequ("ss", instruct) == 1)
		return (swap_ab(stack));
	else if (ft_strequ("pa", instruct) == 1)
		return (push_a(stack));
	else if (ft_strequ("pb", instruct) == 1)
		return (push_b(stack));
	else if (ft_strequ("ra", instruct) == 1)
		return (rotate_a(stack));
	else if (ft_strequ("rb", instruct) == 1)
		return (rotate_b(stack));
	else if (ft_strequ("rr", instruct) == 1)
		return (rotate_ab(stack));
	else if (ft_strequ("rra", instruct) == 1)
		return (rev_rot_a(stack));
	else if (ft_strequ("rrb", instruct) == 1)
		return (rev_rot_b(stack));
	else if (ft_strequ("rrr", instruct) == 1)
		return (rev_rot_ab(stack));
	return (0);
}

static void result(t_stacks *stack)
{
	if (check_sort(stack) == 1)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

static void free_stack(t_stacks *stack)
{
	free(stack->array_a);
	free(stack->array_b);
}

static void fail_response(void)
{
	ft_putendl("Error");
	exit (1);
}

int			main(int ac, char **av)
{	
	t_stacks	stack;
	char		*instr;

	if (ac-- > 1)
	{
		stack.array_a = malloc(sizeof(int) * (ac));
		stack.array_b = malloc(sizeof(int) * (ac));
		if ((assign_array(av, ac, &stack)) != 0)
		{
			while (get_next_line(0, &instr))
			{
				if (swap(instr, &stack) == 0)
					fail_response();
				free(instr);
			}
			result(&stack);	
		}
		else
			ft_putendl("Error");
		free_stack(&stack);
	}
	return (0);
}

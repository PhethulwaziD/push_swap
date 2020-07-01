/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 08:45:34 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/25 15:00:54 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sb_action(t_stacks *stack)
{
	swap_b(stack);
	ft_putendl("sb");
}

static void rb_action(t_stacks *stack)
{
	rotate_b(stack);
	ft_putendl("rb");
}

static void rrb_action(t_stacks *stack)
{
	rev_rot_b(stack);
	ft_putendl("rrb");
}

static void sa_action(t_stacks *stack)
{
	swap_a(stack);
	ft_putendl("sa");
}

static void ra_action(t_stacks *stack)
{
	rotate_a(stack);
	ft_putendl("ra");
}

static void rra_action(t_stacks *stack)
{
	rev_rot_a(stack);
	ft_putendl("rra");
}

static void pb_action(t_stacks *stack)
{
	push_b(stack);
	ft_putendl("pb");
}

static void pa_action(t_stacks *stack)
{
	push_a(stack);
	ft_putendl("pa");
}

void		sort_five(t_stacks *stack)
{
	while (check_sort(stack) == 0)
	{
		if (sb_condition(stack) != 0)
			sb_action(stack);
		else if (rb_condition(stack) != 0)
			rb_action(stack);		
		else if (rrb_condition(stack) != 0)
			rrb_action(stack);
		else if (sa_condition(stack) != 0)
			sa_action(stack);
		else if (ra_condition(stack) != 0)
			ra_action(stack);
		else if (rra_condition(stack) != 0)
			rra_action(stack);
		else if (pb_condition(stack) != 0)
			pb_action(stack);
		else if (pa_condition(stack) != 0)
			pa_action(stack);
	}
}

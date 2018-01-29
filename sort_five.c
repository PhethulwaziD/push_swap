#include "push_swap.h"

static int		half_length(t_stacks *stack)
{
	if ((stack->len_a % 2) == 0)
		return (stack->len_a / 2);
	return ((stack->len_a / 2) + 1);
}

static int	biggest_stack_a(t_stacks *stack)
{
	int		i;
	int		big;

	i = 0;
	if (stack->len_a > 0)
	{
		big = stack->array_a[i];
		while (i < stack->len_a)
		{
			if (stack->array_a[i] > big)
				big = stack->array_a[i];
		i++;
		}
	}
	return (big);
}

static int				small_stack_a(t_stacks *stack)
{
	int			i;
	int			small;

	i = 0;
	if (stack->len_a > 0)
	{
		small = stack->array_a[i];
		while (i < stack->len_a)
		{
			if (stack->array_a[i] < small)
				small = stack->array_a[i];
			i++;
		}
	}
	return (small);
}

static int check_sort_a(t_stacks *stack)
{
	int i;
	int j;

	i = 0;
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

static void sort_a(t_stacks *stack)
{
	int big;

	big = biggest_stack_a(stack);
	while (check_sort_a(stack) == 0)
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

static void push_to_b(t_stacks *stack)
{
	if (stack->len_a > 3)
	{
		while (stack->len_a > 3)
		{
			push_b(stack);
			ft_putendl("pb");
		}
	}
}

static int push_condition(t_stacks *stack)
{
	int i;
	int lst;

	lst = stack->len_a - 1;
	i = 0;
	if (*stack->top_b > *stack->top_a  && *stack->top_b > stack->array_a[lst])
	{
		while (i++ < stack->len_a)
		{
			if (*stack->top_b > stack->array_a[i - 1]\
				&& *stack->top_b < stack->array_a[i])
				return (0);
		}
		return (1);
	}
	return (0);
}

static int push_a_condition(t_stacks *stack)
{
	int lst;

	lst = stack->len_a - 1;
	if (stack->len_b > 0)
	{
		if (*stack->top_b == biggest(stack))
			if (stack->array_a[lst] == biggest_stack_a(stack))
				return (1);
		if (*stack->top_b == smallest(stack))	
			if (*stack->top_b < *stack->top_a && *stack->top_a == small_stack_a(stack))
				return (1);
		if (*stack->top_b != biggest(stack))	
			if (*stack->top_b < *stack->top_a  && *stack->top_b > stack->array_a[lst])
				return (1);
		if (*stack->top_b != biggest(stack)\
			&& *stack->top_b != smallest(stack))	
			if (push_condition(stack) == 1)
				return (1);
	}
	return (0);
}

static int rot_condition_one(t_stacks *stack)
{
	int i;

	i = 0;
	if (stack->len_b > 0)
	{
		while (i++ < stack->len_a)
			if (*stack->top_b > stack->array_a[i - 1] && *stack->top_b < stack->array_a[i])
				if (i <= half_length(stack))
					return (1);
	}
	return (0);
}

static int rot_condition_two(t_stacks *stack)
{
	int i;

	i = 0;
	while (i++ < stack->len_a)
		if (stack->array_a[i] < stack->array_a[i - 1])
			if (i < half_length(stack))
				return (1);
	return (0);
}
static int rotate_a_condtion(t_stacks *stack)
{
	if (rot_condition_one(stack) == 1 && rot_condition_two(stack) == 0)
		return (1);
	if (rot_condition_two(stack) == 1)
		return (1);
	return (0);
}

static int rev_condition_one(t_stacks *stack)
{
	int i;

	i = 0;
	if (stack->len_b > 0)
	{
		while (i++ < stack->len_a)
			if (*stack->top_b > stack->array_a[i - 1] && *stack->top_b < stack->array_a[i])
				if (i >= half_length(stack))
					return (1);
	}
	return (0);
}

static int rev_condition_two(t_stacks *stack)
{
	int i;

	i = 0;
	while (i++ < stack->len_a)
		if (stack->array_a[i] < stack->array_a[i - 1])
			if (i >= half_length(stack))
				return (1);
	return (0);
}

static int rev_a_condition(t_stacks *stack)
{
	if (rev_condition_one(stack) == 1 && rev_condition_two(stack) == 0)
		return (1);
	if (rev_condition_two(stack) == 1)
		return (1);
	return (0);
}

void		sort_five(t_stacks *stack)
{
	push_to_b(stack);
	if (stack->len_a == 3 && check_sort_a(stack) == 0)
		sort_a(stack);
	while (check_sort(stack) == 0)
	{
		if (push_a_condition(stack) == 1)
		{
			push_a(stack);
			ft_putendl("pa");
		}
		else if (rotate_a_condtion(stack) == 1)
		{
			rotate_a(stack);
			ft_putendl("ra");
		}
		else if (rev_a_condition(stack) == 1)
		{
			rev_rot_a(stack);
			ft_putendl("rra");	
		}
	}
}
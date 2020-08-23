#include "push_swap.h"

static int		half_length(t_stacks *stack)
{
	if ((stack->len_b % 2) == 0)
		return (stack->len_b / 2);
	return ((stack->len_b / 2) + 1);
}

static int	big_stack_b(t_stacks *stack)
{
	int		i;
	int		big;

	i = 0;
	if (stack->len_b > 0)
	{
		big = stack->array_b[i];
		while (i < stack->len_b)
		{
			if (stack->array_b[i] > big)
				big = stack->array_b[i];
		i++;
		}
	}
	return (big);
}

static int				small_stack_b(t_stacks *stack)
{
	int			i;
	int			small;

	i = 0;
	if (stack->len_a > 0)
	{
		small = stack->array_b[i];
		while (i < stack->len_b)
		{
			if (stack->array_b[i] < small)
				small = stack->array_b[i];
			i++;
		}
	}
	return (small);
}
/////////////////////////////////////////////////////
static int	rb_condition_one(t_stacks *stack)
{
	int		lst_b;
	int		i;

	lst_b = stack->len_b - 1;
	if (stack->len_b >= 2)
	{

		if (*stack->top_a > big_stack_b(stack) && big_stack_b(stack) != *stack->top_b)
		{
			i = 0;
			while (i < stack->len_b)
			{
				if (big_stack_b(stack) == stack->array_b[i] && i < half_length(stack))
					return (1);
				if (big_stack_b(stack) == stack->array_b[i] && i > half_length(stack))
					return (2);
				i++;
			}
			return (1);
		}
		else if (*stack->top_a < small_stack_b(stack) && small_stack_b(stack) != stack->array_b[lst_b])
		{
			i = 0;
			while (i < stack->len_b)
			{
				if (small_stack_b(stack) == stack->array_b[i] && i < half_length(stack))
					return (1);
				if (small_stack_b(stack) == stack->array_b[i] && i > half_length(stack))
					return (2);
				i++;
			}
		}
	}
	return (0);
}

static int	rb_condition_two(t_stacks *stack)
{
	int 	i;

	i = 1;
	if (stack->len_b >= 2)
	{
		while (i < stack->len_b)
		{
			if (*stack->top_a < stack->array_b[i - 1] && *stack->top_a > stack->array_b[i])
			{
				if (i < half_length(stack) + 1)
					return (1);
				if (i > half_length(stack))
					return (2);
			}
			i++;
		}
	}
	return (0);
}

static int find_position(t_stacks *stack)
{
	if (rb_condition_one(stack) == 1)
		return (1);
	if (rb_condition_one(stack) == 2)
		return (2);
	if (rb_condition_two(stack) == 1)
		return (1);
	if (rb_condition_two(stack) == 2)
		return (2);
	return (0);
}

int			sort_b(t_stacks *stack)
{
	if (find_position(stack) == 1)
		return (1);
	if (find_position(stack) == 2)
		return (2);
	return (0);
}
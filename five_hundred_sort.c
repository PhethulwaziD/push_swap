#include "push_swap.h"

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

static void pa_action(t_stacks *stack)
{
	push_a(stack);
	ft_putendl("pa");
}


static void	reset_pos(int *pos, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		pos[i] = -1;
		i++;
	}
}

static int				half_length(t_stacks *stack)
{
	if ((stack->len_a % 2) >= 1 )
		return ((stack->len_a / 2) + 1);
	return (stack->len_a / 2);
}


int			biggest_val(t_stacks *stack)
{
	int		i;
	int		big;

	i = 0;
	if (stack->len_a > 0)
	{
		big = i;
		while (i < stack->len_a)
		{
			if (stack->array_a[i] > stack->array_a[big])
				big = i;
			i++;
		}
	}
	return (big);
}


static int				smallest_val(t_stacks *stack)
{
	int			i;
	int			small;

	i = 0;
	if (stack->len_a > 0)
	{
		small = i;
		while (i < stack->len_a)
		{
			if (stack->array_a[i] < stack->array_a[small])
				small = i;
			i++;
		}
	}
	return (small);
}

static int	no_previous(int *pos, int j, int len)
{
	int		i;
	i = 0;
	while (i < len)
	{
		if (pos[i] == j)
			return (0);
		i++;
	}
	return (1);
}

static void	assign_pos(t_stacks *stack, int *pos, int len)
{
	int 	i;
	int		j;
	int 	curr;

	i = 1;
	while (i < len)
	{
		j = 0;
		curr = biggest_val(stack);
		while (j < stack->len_a)
		{
			if (no_previous(pos, j, len) == 1 && stack->array_a[j] < stack->array_a[curr])
				curr = j;	
			j++;
		}
		pos[i] = curr;
		i++;
	}
}

static int 	best_position(t_stacks *stack, int *pos, int len)
{
	int		i;
	int		diff;
	int		best;
	int		best_pos;

	i = 0;
	diff = stack->len_a;
	best = diff;
	best_pos = 0;
	while (i < len && pos[i] != -1)
	{
		if (pos[i] > half_length(stack))
			diff = stack->len_a - pos[i];
		else if (pos[i] < half_length(stack))
			diff = pos[i];
		if (diff < best)
		{
			best = diff;
			best_pos = pos[i];
		}

		i++;
	}
	return (best_pos);
}

static void	best_move(t_stacks *stack, int pos)
{
	if (pos == 0)
	{
		while (sort_b(stack) != 0)
		{
			if (sort_b(stack) == 1)
				rb_action(stack);
			else if (sort_b(stack) == 2)
				rrb_action(stack);

		}
		pb_action(stack);
	}
	else if (pos == 1)
		sa_action(stack);
	else if (pos < half_length(stack))
		ra_action(stack);
	else if (pos > half_length(stack))
		rra_action(stack);
}

void		five_hundred_sort(t_stacks *stack)
{
	int		*pos;
	int		best_pos;
	int		lst_a;
	int		len;

	lst_a = stack->len_a - 1;
	len = 15;
	if (stack->len_a <= 100)
		len = 10;
	while (stack->len_a > 0)
	{
		pos =  malloc(sizeof(int) * len);
		reset_pos(pos, len);
		pos[0] = smallest_val(stack);
		assign_pos(stack, pos, len);
		best_pos = best_position(stack, pos, len);
		best_move(stack, best_pos);
		free(pos);
	}
	while (stack->len_b)
	{
		pa_action(stack);
	}
	while (check_sort(stack) == 0)
	{
		if (*stack->top_a > stack->array_a[lst_a])
			ra_action(stack);
	}
}
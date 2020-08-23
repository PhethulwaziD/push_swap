/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:20:09 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/25 14:31:51 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef	struct s_stacks
{
	int	*array_a;
	int len_a;
	int *top_a;
	int	*array_b;
	int len_b;
	int *top_b;
} 				t_stacks;

int			assign_array(char **av, int ac, t_stacks *stack);
int			error(char *arr);
int			check_repeat(t_stacks *stack);
int 		swap_a(t_stacks *stack);
int			sa_condition(t_stacks *stack);
int			swap_b(t_stacks *stack);
int			sb_condition(t_stacks *stack);
int			swap_ab(t_stacks *stack);
int			push_a(t_stacks *stack);
int			pa_condition(t_stacks *stack);
int			push_b(t_stacks *stack);
int			pb_condition(t_stacks *stack);
int			rotate_a(t_stacks *stack);
int			ra_condition(t_stacks *stack);
int			rotate_b(t_stacks *stack);
int			rotate_ab(t_stacks *stack);
int			check_sort(t_stacks *stack);
int			rev_rot_a(t_stacks *stack);
int			rra_condition(t_stacks *stack);
int			rev_rot_b(t_stacks *stack);
int 		rrb_condition(t_stacks *stack);
int			rev_rot_ab(t_stacks *stack);
int 		rb_condition(t_stacks *stack);
void		print_stack(t_stacks *stack);
void		sort_three(t_stacks *stack);
int			biggest(t_stacks *stack);
void		sort_five(t_stacks *stack);
void		sort_hundred(t_stacks *stack);
void		five_hundred_sort(t_stacks *stack);
int			smallest(t_stacks *stack);
int			sort_b(t_stacks *stack);
#endif

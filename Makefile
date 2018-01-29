# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 11:32:50 by pdonga            #+#    #+#              #
#    Updated: 2019/09/25 14:32:24 by pdonga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

FLAGS = -Wall -Werror -Wextra -I. -c

SOURCES = error.c assign_array.c check_repeat.c swap_a.c swap_b.c check_sort.c\
		  swap_ab.c push_a.c push_b.c rotate_a.c rotate_b.c rotate_ab.c\
		  rev_rot_a.c rev_rot_b.c rev_rot_ab.c print_stack.c sort_three.c biggest.c\
		  sort_five.c sa_condition.c sb_condition.c rra_condition.c ra_condition.c pa_condition.c\
		  pb_condition.c smallest.c rrb_condition.c rb_condition.c sort_hundred.c


INCLUDE = push_swap.h

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SOURCES)
	@ar rv $(NAME) $(OBJECTS) $(INCLUDE)
	@ranlib $(NAME)
	@make -C ./libft
	gcc -o push_swap push_swap.c push_swap.a ./libft/libft.a
	gcc -o checker checker.c push_swap.a ./libft/libft.a


make_libft:
	@make -C ./libft

clean:
	@rm -f $(OBJECTS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
 
re: fclean all

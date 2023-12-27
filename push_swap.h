/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:40:32 by egualand          #+#    #+#             */
/*   Updated: 2023/12/02 15:27:44 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef LIBFT_H
#  include "libft/libft.h"
# endif

typedef struct s_operations
{
	int				rx;
	int				rrx;
}					t_operations;

typedef struct s_total_operations
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
}					t_total_operations;

void				ft_error(int code);
void				input_error(int argc, char **argv);
void				sort_lists(t_list **stack_a, t_list **stack_b);
t_list				*create_stack(int argc, char **argv);
void				perform_operation(char *c, t_list **head_a,
						t_list **head_b);
void				swap_stack(t_list **head);
void				push_stack(t_list **head, t_list **head2);
void				reverse_stack(t_list **head);
void				rotate_stack(t_list **head);
void				print_list(t_list *head);
int					count_rx(t_list **stack, int num);
int					count_rrx(t_list **stack, int num);
int					count_rr(int *ra_count, int *rb_count);
int					count_rrr(int *rra_count, int *rrb_count);
t_operations		count_stack_operations(t_list **stack, int num);
int					find_min(t_list **stack);
int					find_max(t_list **stack);
int					find_best_num(t_list **stack, int num);
int					sum_operations(t_operations ops_a, t_operations ops_b);
t_total_operations	get_total_operations(t_operations ops_a,
						t_operations ops_b);
int					count_operations(t_list **stack_a, t_list **stack_b,
						int num);
void				perform_operations(t_list **stack_a, t_list **stack_b,
						int num);
void				sort_two(t_list **stack_a);
void				sort_three(t_list **stack_a);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				ft_free_matrix(char **argv);

#endif

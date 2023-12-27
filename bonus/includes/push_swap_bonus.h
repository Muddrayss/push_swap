/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:40:32 by egualand          #+#    #+#             */
/*   Updated: 2023/12/09 12:02:27 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef LIBFT_H
#  include "../../libft/libft.h"
# endif

void	ft_error(int code);
void	input_error(int argc, char **argv);
t_list	*create_stack(int argc, char **argv);
void	perform_operation(char *c, t_list **head_a, t_list **head_b);
void	swap_stack(t_list **head);
void	push_stack(t_list **head, t_list **head2);
void	reverse_stack(t_list **head);
void	rotate_stack(t_list **head);
void	ft_free_matrix(char **argv);
void	print_list(t_list *head);

#endif

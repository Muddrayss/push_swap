/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:40:32 by egualand          #+#    #+#             */
/*   Updated: 2023/11/19 16:52:34 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

void	sort_lists(t_list **stack_a, t_list **stack_b);
t_list	*create_stack(int argc, char **argv);
void	perform_operation(char *c, t_list **head_a, t_list **head_b);
void	swap_stack(t_list **head);
void	push_stack(t_list **head, t_list **head2);
void 	reverse_stack(t_list **head);
void	rotate_stack(t_list **head);
void	printList(t_list *head);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:59:08 by egualand          #+#    #+#             */
/*   Updated: 2023/12/09 12:24:26 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

static void	perform_ss(t_list **head_a, t_list **head_b)
{
	swap_stack(head_a);
	swap_stack(head_b);
}

static void	perform_rr(t_list **head_a, t_list **head_b)
{
	rotate_stack(head_a);
	rotate_stack(head_b);
}

static void	perform_rrr(t_list **head_a, t_list **head_b)
{
	reverse_stack(head_a);
	reverse_stack(head_b);
}

void	perform_operation(char *c, t_list **head_a, t_list **head_b)
{
	if (ft_strcmp(c, "sa\n") == 0)
		swap_stack(head_a);
	else if (ft_strcmp(c, "sb\n") == 0)
		swap_stack(head_b);
	else if (ft_strcmp(c, "ss\n") == 0)
		perform_ss(head_a, head_b);
	else if (ft_strcmp(c, "pa\n") == 0)
		push_stack(head_a, head_b);
	else if (ft_strcmp(c, "pb\n") == 0)
		push_stack(head_b, head_a);
	else if (ft_strcmp(c, "ra\n") == 0)
		rotate_stack(head_a);
	else if (ft_strcmp(c, "rb\n") == 0)
		rotate_stack(head_b);
	else if (ft_strcmp(c, "rr\n") == 0)
		perform_rr(head_a, head_b);
	else if (ft_strcmp(c, "rra\n") == 0)
		reverse_stack(head_a);
	else if (ft_strcmp(c, "rrb\n") == 0)
		reverse_stack(head_b);
	else if (ft_strcmp(c, "rrr\n") == 0)
		perform_rrr(head_a, head_b);
	else
		ft_error(17);
}

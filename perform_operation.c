/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:59:08 by egualand          #+#    #+#             */
/*   Updated: 2023/11/26 16:31:50 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_strcmp(c, "sa") == 0)
		swap_stack(head_a);
	else if (ft_strcmp(c, "sb") == 0)
		swap_stack(head_b);
	else if (ft_strcmp(c, "ss") == 0)
		perform_ss(head_a, head_b);
	else if (ft_strcmp(c, "pa") == 0)
		push_stack(head_a, head_b);
	else if (ft_strcmp(c, "pb") == 0)
		push_stack(head_a, head_b);
	else if (ft_strcmp(c, "ra") == 0)
		rotate_stack(head_a);
	else if (ft_strcmp(c, "rb") == 0)
		rotate_stack(head_b);
	else if (ft_strcmp(c, "rr") == 0)
		perform_rr(head_a, head_b);
	else if (ft_strcmp(c, "rra") == 0)
		reverse_stack(head_a);
	else if (ft_strcmp(c, "rrb") == 0)
		reverse_stack(head_b);
	else if (ft_strcmp(c, "rrr") == 0)
		perform_rrr(head_a, head_b);
	ft_putstr_fd(c, 1);
	ft_putendl_fd("", 1);
}

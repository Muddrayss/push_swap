/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:53:21 by egualand          #+#    #+#             */
/*   Updated: 2023/11/24 17:54:59 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rx(t_list **stack, int num)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp && tmp->next && tmp->value != num)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	count_rrx(t_list **stack, int num)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp && tmp->next && tmp->value != num)
	{
		tmp = tmp->next;
	}
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	count_rr(int *ra_count, int *rb_count)
{
	int	count;

	count = 0;
	while (*ra_count > 0 && *rb_count > 0)
	{
		count++;
		(*ra_count)--;
		(*rb_count)--;
	}
	return (count);
}

int	count_rrr(int *rra_count, int *rrb_count)
{
	int	count;

	count = 0;
	while (*rra_count > 0 && *rrb_count > 0)
	{
		count++;
		(*rra_count)--;
		(*rrb_count)--;
	}
	return (count);
}

t_operations	count_stack_operations(t_list **stack, int num)
{
	t_operations	operations;

	operations.rx = count_rx(stack, num);
	operations.rrx = count_rrx(stack, num);
	return (operations);
}

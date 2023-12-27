/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_count_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:53:25 by egualand          #+#    #+#             */
/*   Updated: 2023/11/25 14:30:28 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_total_operations	set_total_operations(int ra, int rb, int rra,
		int rrb)
{
	t_total_operations	total_operations;

	total_operations.ra = ra;
	total_operations.rb = rb;
	total_operations.rra = rra;
	total_operations.rrb = rrb;
	return (total_operations);
}

int	find_best_num(t_list **stack, int num)
{
	int		best_num;
	int		best_sum;
	int		i;
	t_list	*tmp;

	best_num = 0;
	best_sum = 0;
	i = ft_lstsize(*stack);
	tmp = *stack;
	while (i > 0)
	{
		if ((best_sum == 0 && (num - tmp->value) > 0) || (num - tmp->value > 0
				&& (num - tmp->value) < best_sum))
		{
			best_sum = (num - tmp->value);
			best_num = tmp->value;
		}
		tmp = tmp->next;
		i--;
	}
	return (best_num);
}

int	sum_operations(t_operations ops_a, t_operations ops_b)
{
	int	sum;

	sum = 0;
	if (ops_b.rx <= ops_b.rrx)
	{
		if (ops_a.rx <= ops_a.rrx)
			sum = count_rr(&ops_a.rx, &ops_b.rx) + ops_a.rx + ops_b.rx;
		else
			sum = ops_b.rx + ops_a.rrx;
	}
	else
	{
		if (ops_a.rx <= ops_a.rrx)
			sum = ops_b.rrx + ops_a.rx;
		else
			sum = count_rrr(&ops_a.rrx, &ops_b.rrx) + ops_a.rrx + ops_b.rrx;
	}
	return (sum);
}

t_total_operations	get_total_operations(t_operations ops_a, t_operations ops_b)
{
	t_total_operations	total_operations;

	if (ops_b.rx <= ops_b.rrx)
	{
		if (ops_a.rx <= ops_a.rrx)
			total_operations = set_total_operations(ops_a.rx, ops_b.rx, 0, 0);
		else
			total_operations = set_total_operations(0, ops_b.rx, ops_a.rrx, 0);
	}
	else
	{
		if (ops_a.rx <= ops_a.rrx)
			total_operations = set_total_operations(ops_a.rx, 0, 0, ops_b.rrx);
		else
			total_operations = set_total_operations(0, 0, ops_a.rrx, ops_b.rrx);
	}
	return (total_operations);
}

int	count_operations(t_list **stack_a, t_list **stack_b, int num)
{
	t_operations	operations_a;
	t_operations	operations_b;

	operations_a = count_stack_operations(stack_a, num);
	operations_a.rrx += 1;
	if (num < find_min(stack_b))
	{
		operations_b = count_stack_operations(stack_b, find_min(stack_b));
		operations_b.rx += 1;
	}
	else
	{
		operations_b = count_stack_operations(stack_b, find_best_num(stack_b,
					num));
		operations_b.rrx += 1;
	}
	return (sum_operations(operations_a, operations_b) + 1);
}

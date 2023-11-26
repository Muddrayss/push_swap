/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:53:37 by egualand          #+#    #+#             */
/*   Updated: 2023/11/24 17:56:03 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operations	calculate_operations_a(t_list **stack_a, int num)
{
	t_operations	operations_a;

	operations_a = count_stack_operations(stack_a, num);
	operations_a.rrx += 1;
	return (operations_a);
}

static t_operations	calculate_operations_b(t_list **stack_b, int num)
{
	t_operations	operations_b;

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
	return (operations_b);
}

static void	perform_combined_operations(t_list **stack_a, t_list **stack_b,
		t_total_operations *total_ops)
{
	while (total_ops->ra > 0 && total_ops->rb > 0)
	{
		perform_operation("rr", stack_a, stack_b);
		total_ops->ra--;
		total_ops->rb--;
	}
	while (total_ops->rra > 0 && total_ops->rrb > 0)
	{
		perform_operation("rrr", stack_a, stack_b);
		total_ops->rra--;
		total_ops->rrb--;
	}
}

static void	perform_individual_operations(t_list **stack_a, t_list **stack_b,
		t_total_operations *total_ops)
{
	while (total_ops->ra > 0)
	{
		perform_operation("ra", stack_a, stack_b);
		total_ops->ra--;
	}
	while (total_ops->rb > 0)
	{
		perform_operation("rb", stack_a, stack_b);
		total_ops->rb--;
	}
	while (total_ops->rra > 0)
	{
		perform_operation("rra", stack_a, stack_b);
		total_ops->rra--;
	}
	while (total_ops->rrb > 0)
	{
		perform_operation("rrb", stack_a, stack_b);
		total_ops->rrb--;
	}
}

void	perform_operations(t_list **stack_a, t_list **stack_b, int num)
{
	t_operations		operations_a;
	t_operations		operations_b;
	t_total_operations	total_operations;

	operations_a = calculate_operations_a(stack_a, num);
	operations_b = calculate_operations_b(stack_b, num);
	total_operations = get_total_operations(operations_a, operations_b);
	perform_combined_operations(stack_a, stack_b, &total_operations);
	perform_individual_operations(stack_a, stack_b, &total_operations);
	perform_operation("pb", stack_a, stack_b);
}

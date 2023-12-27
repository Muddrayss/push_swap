/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:54:21 by egualand          #+#    #+#             */
/*   Updated: 2023/12/09 13:51:26 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_sort(t_list **stack_a, t_list **stack_b)
{
	int				i;
	t_operations	operations_b;

	i = ft_lstsize(*stack_b);
	operations_b = count_stack_operations(stack_b, find_min(stack_b));
	operations_b.rx += 1;
	if (operations_b.rx <= operations_b.rrx)
	{
		while (operations_b.rx > 0)
		{
			perform_operation("rb", stack_a, stack_b);
			operations_b.rx--;
		}
	}
	else
	{
		while (operations_b.rrx > 0)
		{
			perform_operation("rrb", stack_a, stack_b);
			operations_b.rrx--;
		}
	}
	while (i-- > 0)
		perform_operation("pa", stack_a, stack_b);
}

static int	find_minimum_operations(t_list **stack_a, t_list **stack_b,
		int list_size, int *min_num)
{
	int		min_operations;
	int		curr_operations;
	t_list	*tmp;
	int		j;

	min_operations = 0;
	tmp = *stack_a;
	j = list_size;
	while (j > 0 && tmp)
	{
		curr_operations = count_operations(stack_a, stack_b, tmp->value);
		if (min_operations == 0 || curr_operations < min_operations)
		{
			min_operations = curr_operations;
			*min_num = tmp->value;
		}
		tmp = tmp->next;
		j--;
	}
	return (min_operations);
}

static void	perform_sorting_loop(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	min_num;

	i = ft_lstsize(*stack_a);
	while (i > 0)
	{
		find_minimum_operations(stack_a, stack_b, i, &min_num);
		perform_operations(stack_a, stack_b, min_num);
		i = ft_lstsize(*stack_a);
	}
}

void	sort_lists(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_lstsize(*stack_a);
	if (i == 2)
		sort_two(stack_a);
	else if (i == 3)
		sort_three(stack_a);
	else if (i == 4)
		sort_four(stack_a, stack_b);
	else if (i == 5)
		sort_five(stack_a, stack_b);
	else
	{
		perform_operation("pb", stack_a, stack_b);
		perform_operation("pb", stack_a, stack_b);
		perform_sorting_loop(stack_a, stack_b);
		finish_sort(stack_a, stack_b);
	}
}

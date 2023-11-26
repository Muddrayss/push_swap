/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:02:06 by egualand          #+#    #+#             */
/*   Updated: 2023/11/26 17:13:11 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	if ((*stack_a)->value == max)
		perform_operation("ra", stack_a, NULL);
	if ((*stack_a)->next->value == max)
		perform_operation("rra", stack_a, NULL);
	if ((*stack_a)->value > (*stack_a)->next->value)
		perform_operation("sa", stack_a, NULL);
}

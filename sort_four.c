/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:02:51 by egualand          #+#    #+#             */
/*   Updated: 2023/11/26 17:16:07 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(stack_a);
	while ((*stack_a)->value != min)
		perform_operation("ra", stack_a, NULL);
	perform_operation("pb", stack_a, stack_b);
	sort_three(stack_a);
	perform_operation("pa", stack_b, stack_a);
}

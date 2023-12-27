/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:02:51 by egualand          #+#    #+#             */
/*   Updated: 2023/12/02 14:35:08 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = find_min(stack_a);
	if (ft_lstlast(*stack_a)->value == min)
		perform_operation("rra", stack_a, NULL);
	while ((*stack_a)->value != min)
		perform_operation("ra", stack_a, NULL);
	perform_operation("pb", stack_a, stack_b);
	sort_three(stack_a);
	perform_operation("pa", stack_b, stack_a);
}

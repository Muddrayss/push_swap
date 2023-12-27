/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:53:13 by egualand          #+#    #+#             */
/*   Updated: 2023/12/09 13:46:52 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **stack)
{
	t_list	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->value;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value < min)
			min = tmp->value;
	}
	return (min);
}

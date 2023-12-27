/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:01:12 by egualand          #+#    #+#             */
/*   Updated: 2023/12/02 16:59:32 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

void	reverse_stack(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*head && (*head)->next)
	{
		tmp = *head;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *head;
		*head = tmp2;
	}
}

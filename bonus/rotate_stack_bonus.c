/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:01:58 by egualand          #+#    #+#             */
/*   Updated: 2023/12/02 16:59:36 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

void	rotate_stack(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp2 = *head;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = NULL;
	}
}

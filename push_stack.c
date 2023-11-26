/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:00:37 by egualand          #+#    #+#             */
/*   Updated: 2023/11/24 17:55:09 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_list **head, t_list **head2)
{
	t_list	*tmp;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = *head2;
		*head2 = tmp;
	}
}

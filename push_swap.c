/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:45:39 by egualand          #+#    #+#             */
/*   Updated: 2023/12/02 17:04:39 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(int value)
{
	value = 0;
}

static void	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return ;
		tmp = tmp->next;
	}
	ft_lstclear(stack_a, del);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = (t_list *)create_stack(argc, argv);
	if (a == NULL)
		ft_error(0);
	b = NULL;
	is_sorted(&a);
	sort_lists(&a, &b);
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}

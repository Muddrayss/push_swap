/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:58:32 by egualand          #+#    #+#             */
/*   Updated: 2023/12/09 13:55:19 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

static void	del(int value)
{
	value = 0;
}

static int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	executing(t_list *stack_a, t_list *stack_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		perform_operation(cmd, &stack_a, &stack_b);
		free(cmd);
	}
	if (is_sorted(&stack_a) && ft_lstsize(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = (t_list *)create_stack(argc, argv);
	if (a == NULL)
		ft_error(0);
	b = NULL;
	executing(a, b);
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}

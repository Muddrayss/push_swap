/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:53:05 by egualand          #+#    #+#             */
/*   Updated: 2023/12/07 14:52:03 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_list	*process(int argc, char **argv)
{
	t_list	*a;
	t_list	*new;
	int		i;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

static t_list	*sub_process(char **argv)
{
	t_list	*a;
	t_list	*new;
	int		i;

	i = 0;
	a = NULL;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&a, new);
		i++;
	}
	ft_free_matrix(argv);
	return (a);
}

static int	ft_split_count(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

t_list	*create_stack(int argc, char **argv)
{
	char	**tmp;

	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (check_duplicates(ft_split_count(tmp), tmp))
		{
			ft_free_matrix(tmp);
			ft_error(9);
		}
		input_error(ft_split_count(tmp), tmp);
		return (sub_process(tmp));
	}
	else
	{
		if (check_duplicates(argc - 1, &argv[1]))
			ft_error(10);
		input_error(argc - 1, &argv[1]);
		return (process(argc, argv));
	}
}

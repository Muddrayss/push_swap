/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:04 by egualand          #+#    #+#             */
/*   Updated: 2023/12/09 11:53:36 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_bonus.h"

void	ft_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
}

static void	check_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			ft_error(3);
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && (argv[i][j] == '-'
					|| argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				ft_error(4);
			}
			j++;
		}
		i++;
	}
}

static void	check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(5);
		i++;
	}
}

void	input_error(int argc, char **argv)
{
	if (argc < 1)
		ft_error(6);
	check_integers(argc, argv);
	check_int_size(argc, argv);
}

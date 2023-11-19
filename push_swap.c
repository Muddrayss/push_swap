/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:45:39 by egualand          #+#    #+#             */
/*   Updated: 2023/11/16 17:54:22 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	else
		a = (t_list *)create_stack(argc, argv);
	b = NULL;
	sort_lists(&a, &b);
	return (0);
}

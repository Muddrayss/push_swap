/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:55:47 by egualand          #+#    #+#             */
/*   Updated: 2023/11/24 17:57:26 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int *(*f)(int), void (*del)(int))
{
	t_list	*first;
	t_list	*new;
	int		*res;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		res = f(lst->value);
		new = ft_lstnew(*res);
		if (!new)
		{
			del(*res);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

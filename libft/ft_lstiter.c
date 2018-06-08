/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:30:28 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/06 21:30:34 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;

	tmp = NULL;
	tmp = lst;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
/*
**Description - Iterates the list lst and applies the function f to each link.
**Param. #1 A pointer to the first link of a list.
**Param. #2 The address of a function to apply to each link of a list.
**Return value - None.
**Libc functions -None
*/

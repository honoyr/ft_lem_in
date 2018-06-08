/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:43:42 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/08 14:43:46 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmswap(t_list **lst, t_list *add)
{
	t_list	*x;
	t_list	*tmp;

	tmp = NULL;
	x = NULL;
	if (lst && add)
	{
		tmp = *lst;
		x = tmp->next;
		tmp->next = add;
		while (add->next != NULL)
		{
			add = add->next;
		}
		add->next = x;
	}
}
/*
**The function add the "add" inside list to "lst".
**We put new list (add) to next element after element that we had as
**a parametr.
**Param. #1 The address of a pointer to the first link of a list.
**Param. #2 The link to add to next of the list and add end (residue).
**Return value - None.
**Libc functions -None
*/

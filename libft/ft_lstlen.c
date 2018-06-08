/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:33:03 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/08 15:33:05 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
/*
**The function count the element of the list.
**Param. #1 The address of a pointer to the first link of a list.
**Return value - None.
**Libc functions -None
*/

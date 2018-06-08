/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:59:05 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/08 15:59:07 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **lst)
{
	t_list *tmp;

	tmp = NULL;
	if (lst)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			ft_putstr(tmp->content);
			ft_putchar('\n');
			tmp = tmp->next;
		}
	}
}
/*
**The function print lists.
**Param. #1 The address of a pointer to the first link of a list.
**Return value - None.
**Libc functions -None
*/

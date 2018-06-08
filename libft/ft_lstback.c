/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:28:43 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/08 17:28:47 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstback(t_list **lst, t_list *add)
{
	t_list *tmp;

	tmp = NULL;
	if (lst && add)
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
	}
}
/*
**The funcction takes as argumen two list and add at
**the back "add" to "lst". The last element of the list
**must be pointed to NULL;
*/

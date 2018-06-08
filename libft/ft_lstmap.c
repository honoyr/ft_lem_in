/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:42:40 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/06 21:42:45 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*head_new;
	t_list	*tmp;

	head = NULL;
	head_new = NULL;
	tmp = NULL;
	if (lst && f)
	{
		head = lst;
		head_new = f(lst);
		head = head->next;
		tmp = head_new;
		while (head != NULL)
		{
			tmp->next = f(head);
			tmp = tmp->next;
			head = head->next;
		}
		tmp->next = NULL;
		return (head_new);
	}
	return (NULL);
}
/*
**Description - Iterates a list lst and applies the function f
**to each link to create a “fresh” list (using malloc(3))
**resulting from the suc- cessive applications of f.
**If the allocation fails, the function returns NULL.
**Param. #1 A pointer to the first link of a list.
**Param. #2 The address of a function to apply to each link of a list.
**Return value - None.
**Libc functions -None
*/

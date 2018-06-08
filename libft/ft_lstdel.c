/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:45:59 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/06 20:46:01 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = (*alst)->next;
		}
		alst = NULL;
	}
}
/*
**Takes as a parameter the adress of a pointer to a link
**and frees the memory of this link and every successors
**of that link using the functions del and free(3).
**Finally the pointer to the link that was just freed must be set to NULL
**(quite similar to the function ft_memdel from the mandatory part).
**Param. #1 The address of a pointer to the
**first link of a list that needs to be freed.
**Return value - None.
**Libc functions - free(3)
*/

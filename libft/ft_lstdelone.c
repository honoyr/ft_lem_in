/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:39:27 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/06 17:39:29 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	alst = NULL;
}
/*
**Description
**Takes as a parameter a link’s pointer address and frees the memory
**of the link’s content using the function del given as a parameter,
**then frees the link’s memory using free(3). The memory of next must
**not be freed under any circumstance. Finally,
**the pointer to the link that was just freed must be set to NULL
**(quite similar to the function ft_memdel in the mandatory part).
**Param. #1 The adress of a pointer to a link that needs to be freed.
**Return value - None.
**Libc functions - free(3)
** insted of free(*alst) we can use ft_memdel((void**)alst);
*/

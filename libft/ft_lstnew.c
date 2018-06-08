/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:23:21 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/05 17:23:24 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!(new->content = (char*)malloc(sizeof(char) * content_size)))
		ft_memdel((void**)new);
	else
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
			new->next = NULL;
		}
		else
		{
			new->content = ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
			new->next = NULL;
		}
	}
	return (new);
}
/*
**Allocates (with malloc(3)) and returns a “fresh” link.
**The variables content and content_size of the new link
**are initialized by copy of the parameters of the function.
**If the pa- rameter content is nul, the variable content is
**initialized to NULL and the variable content_size is initialized
**to 0 even if the parameter content_size isn’t.
**The variable next is initialized to NULL.
**If the allocation fails, the function returns NULL.
**Param. #1 The content to put in the new link.
**Param. #2 The size of the content of the new link.
**Return value The new link.
*/

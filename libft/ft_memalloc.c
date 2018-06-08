/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:31:08 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/22 19:32:02 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * size);
	if (ptr != NULL)
	{
		while (size > 0)
		{
			ptr[size - 1] = 0;
			size--;
		}
		return (ptr);
	}
	else
		return (NULL);
}
/*
**Ф-я выделяет и чистит память, возврацая указатель.
**Allocates (with malloc(3)) and returns a “fresh” memory area.
**The memory allocated is initialized to 0.
**If the alloca- tion fails, the function returns NULL.
*/

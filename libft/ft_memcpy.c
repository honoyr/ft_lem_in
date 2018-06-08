/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:13:02 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/15 20:22:12 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	return (dst);
}
/*
**The memcpy() function copies n bytes from memory area src to memory area
**dst.  If dst and src overlap, behavior is undefined.  Applications in
**which dst and src might overlap should use memmove(3) instead.
**RETURN VALUES
**The memcpy() function returns the original value of dst.
*/

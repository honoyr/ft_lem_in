/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:37:34 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/09 17:37:37 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t max;
	size_t size_dst;

	i = 0;
	j = 0;
	size_dst = ft_strlen(dst);
	if (size != 0 && size_dst < size)
	{
		max = size - size_dst - 1;
		while (dst[i] != '\0')
			i++;
		while ((j < max) && (src[j] != '\0'))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (size_dst + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}

/*
**The strlcpy() and strlcat() functions copy and concatenate strings
**with the same input parameters and output result as snprintf(3).
**They are designed to be safer,
**more consistent, and less error prone replacements for
**the easily misused functions strncpy(3) and strncat(3).
**strlcpy() and strlcat() take the full size
**of the destination buffer and guarantee
**NUL-termination if there is room.
**Note that room for the NUL should be included in dstsize.
**
**strlcpy() copies up to dstsize - 1 characters from the string src to dst,
**NUL-terminating the result if dstsize is not 0.
**
**strlcat() appends string src to the end of dst.
**It will append at most dstsize - strlen(dst) - 1 characters.
**It will then NUL-terminate,
**unless dstsize is 0 or the original dst string was longer than dstsize
**(in practice this should not happen as it
**means that either dstsize is incorrect or that dst is not a proper string).
**
**If the src and dst strings overlap, the behavior is undefined.
*/

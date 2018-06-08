/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:40:53 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/16 20:40:55 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst > src)
	{
		if (len != 0)
		{
			len--;
			while (len > 0)
			{
				*(char*)(dst + len) = *(char*)(src + len);
				len--;
			}
			*(char*)(dst + len) = *(char*)(src + len);
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
/*
**Фун-я защищает от overlap (прекрытие\наложение) Когда может возникнуть
**ситуация итерируем &dst[1], &dst[0], 3 (байта) -> HELLO = HHH
**поэтому мы сравниваем указатели, если dst больше str то мы будем
**копировать с конца str на len -му байту, уменньшая его.
**memmove() function copies len bytes from string src to string dst.
**The two strings may overlap; the copy is always done in a
**non-destructive manner.
**RETURN VALUES
**The memmove() function returns the original value of dst*
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:21:54 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/16 20:00:27 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		if (*(unsigned char*)(src + i) == (unsigned char)c)
		{
			return ((unsigned char*)(dst + i + 1));
		}
		i++;
	}
	return (NULL);
}
/*
**Функция memccpy() копирует содержимое области памяти, на которую
**указывает source, в область памяти, на которую указывает dest.
**Операция копирования заканчивается, когда скопи­ровано count байт
**или после копирования первого вхождения символа ch. Функция возвращает
**указатель на конец области dest, если символ ch был найден, или NULL,
**если ch не входит в source.
**The memccpy() function copies bytes from string src to string dst.  If
**the character c (as converted to an unsigned char) occurs in the string
**src, the copy stops and a pointer to the byte after the copy of c in the
**string dst is returned.  Otherwise, n bytes are copied, and a NULL
**pointer is returned.
**The source and destination strings should not overlap, as the behavior
**is undefined
*/

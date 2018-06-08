/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:13:20 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/17 21:13:24 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n &&
		*((unsigned char *)(s1 + i)) == *((unsigned char *)(s2 + i)))
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}
/*
**функция сравнивает до n байт, блоков памяти обеих вхождениях по указателям.
**Возвращает значение 0 если блоки равны,
**в ином случае разницу между вхождениями по ASCII н-р А и а = 32.
**Нулевое значение указывает, что содержимое обоих блоков памяти равны.
**The memcmp() function compares byte string s1 against byte string s2.
**Both strings are assumed to be n bytes long.
**RETURN VALUES
**The memcmp() function returns zero if the two strings are identical,
**otherwise returns the difference between the first two differing bytes
**(treated as unsigned char values, so that `\200' is greater than `\0',
**for example).Zero-length strings are always identical.
*/

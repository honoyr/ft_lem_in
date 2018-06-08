/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:44:56 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/30 18:44:58 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_help(char *ptr, int size, long long int n)
{
	if (n < 0)
	{
		ptr[0] = '-';
		if (n == -2147483648)
		{
			ptr[size] = '8';
			size--;
			n = 214748364;
		}
		else
			n = -n;
	}
	if (n == 0)
		ptr[size] = '0';
	while (n != 0)
	{
		ptr[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (ptr);
}

char			*ft_itoa(long long int n)
{
	char	*ptr;
	int		size;

	ptr = NULL;
	size = ft_countsize(n);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr != NULL)
	{
		ptr[size] = '\0';
		size--;
		ptr = ft_help(ptr, size, n);
	}
	return (ptr);
}
/*
**Allocate (with malloc(3)) and returns a “fresh” string
**ending with ’\0’ representing the integer n given as argument.
**Negative numbers must be supported.
**If the allocation fails, the function returns NULL.
**Param. #1 The integer to be transformed into a string.
**Return value The string representing the integer passed as argument.
**Libc functions malloc(3)
*/

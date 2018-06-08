/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:12:54 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/17 15:12:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	tochar_c;

	i = 0;
	tochar_c = (unsigned char)c;
	while (i < n)
	{
		if (*((unsigned char*)(s + i)) == tochar_c)
		{
			return ((unsigned char*)(s + i));
		}
		i++;
	}
	return (NULL);
}
/*
**The memchr() function locates the first occurrence of c (converted to an
**unsigned char) in string s.
**RETURN VALUES
**The memchr() function returns a pointer to the byte located, or NULL if
**no such byte exists within n bytes.
*/

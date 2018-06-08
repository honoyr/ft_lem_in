/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:22:24 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/08 21:22:26 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned int		size;

	i = 0;
	size = 0;
	while (s1[size] != '\0')
	{
		size++;
	}
	while (i < n && s2[i])
	{
		s1[size] = s2[i];
		size++;
		i++;
	}
	s1[size] = '\0';
	return (s1);
}
/*
**The strcat() and strncat() functions append a copy of the
**null-terminated string s2 to the end of the null-terminated string s1,
**then add a terminating `\0'.  The string s1 must have
**sufficient space to hold the result.
**
**The strncat() function appends not more than n characters from s2,
**and then adds a terminating `\0'.
**The source and destination strings should not overlap,
**as the behavior is undefined.
*/

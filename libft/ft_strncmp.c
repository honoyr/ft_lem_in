/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:27:53 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/14 14:27:56 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	if (!n)
		return (0);
	while ((unsigned char)s1[x] == (unsigned char)s2[x]
		&& x < n && s1[x] && s2[x])
		x++;
	if (x == n)
		return (0);
	else
		return ((int)((unsigned char)s1[x] - (unsigned char)s2[x]));
}
/*
**The strcmp() and strncmp() functions lexicographically compare the
**null-terminated strings s1 and s2.
**The strncmp() function compares not more than n characters.  Because
**strncmp() is designed for comparing strings rather than binary data,
**characters that appear after a `\0' character are not compared.
**The strcmp() and strncmp() functions return an integer greater than,
**equal to, or less than 0, according as the string s1 is greater
**than, equal to, or less than the string s2.  The comparison is done
**using unsigned characters, so that `\200' is greater than `\0'.
*/

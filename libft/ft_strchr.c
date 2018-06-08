/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:55:10 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/10 13:55:19 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s != (char)c && *s != '\0')
		{
			s++;
		}
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
/*
**The strchr() function locates the first occurrence of
**c (converted to a char) in the string
**pointed to by s.  The terminating null character is
**considered to be part of the string;
**therefore if c is `\0', the functions locate the terminating `\0'.
**The strrchr() function is identical to strchr(),
**except it locates the last occurrence of c.
**RETURN VALUES
**The functions strchr() and strrchr() return
**a pointer to the located character, or NULL if
**the character does not appear in the string.
*/

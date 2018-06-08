/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:24:59 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/10 19:29:49 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		check;

	check = ft_strlen(s);
	while (s[check] != (char)c && check != 0)
	{
		check--;
	}
	if (s[check] == (char)c)
		return ((char *)&s[check]);
	return (NULL);
}
/*
**The strchr() function locates the first occurrence of c
**(converted to a char) in the string
**pointed to by s.  The terminating null character is
**considered to be part of the string;
**therefore if c is `\0', the functions locate the terminating `\0'.
**The strrchr() function is identical to strchr(),
**except it locates the last occurrence of c.
**RETURN VALUES
**The functions strchr() and strrchr() return a pointer
**to the located character, or NULL if
**the character does not appear in the string.
*/

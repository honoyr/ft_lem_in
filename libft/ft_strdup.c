/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:41:34 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/02 13:44:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dups1;
	int		i;

	i = 0;
	dups1 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dups1 != NULL)
	{
		while (s1[i] != '\0')
		{
			dups1[i] = s1[i];
			i++;
		}
		dups1[i] = '\0';
	}
	return (dups1);
}
/*
**Ф-я выделяет достаточно памяти для копии s1,
**корирует каждый элемент в новый стринг.
**The strdup() function allocates sufficient memory for a copy of the
**string s1, does the copy, and returns a pointer to it.  The pointer may
**subsequently be used as an argument to the function free(3).
**If insufficient memory is available,
**NULL is returned and errno is set to ENOMEM.
**The strndup() function copies at most n characters from the string s1
**always NUL terminating the copied string.
*/

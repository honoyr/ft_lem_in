/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:35:46 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/25 20:01:29 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = NULL;
	if (s != NULL)
	{
		ptr = ft_strnew(len);
		if (ptr != NULL)
		{
			while (i != len && s[start] != '\0')
			{
				ptr[i] = s[start];
				start++;
				i++;
			}
			ptr[i] = '\0';
		}
	}
	return (ptr);
}
/*
**Allocates (with malloc(3)) and returns a “fresh” substring
**from the string given as argument. The substring begins at
**indexstart and is of size len. If start and len aren’t refering
**to a valid substring, the behavior is undefined.
**If the allocation fails, the function returns NULL.
**Param. #1 The string from which create the substring.
**Param. #2 The start index of the substring.
**Param. #3 The size of the substring.
**Return value The substring.
*/

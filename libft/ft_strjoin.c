/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:02:19 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/25 20:40:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	lens1;
	size_t	lens2;

	new = NULL;
	if (s1 && s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		new = ft_strnew(lens1 + lens2);
		if (new != NULL)
		{
			ft_strncpy(new, s1, lens1);
			ft_strncpy(&new[lens1], s2, lens2);
		}
	}
	return (new);
}
/*
**Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
**result of the concatenation of s1 and s2.
**If the allocation fails the function returns NULL.
**Param. #1 The prefix string.
**Param. #2 The su x string.
**Return value The “fresh” string result of the concatenation of the 2 strings.
*/

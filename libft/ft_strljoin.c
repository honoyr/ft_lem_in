/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:03:27 by dgonor            #+#    #+#             */
/*   Updated: 2018/02/02 13:11:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strljoin(char **s1, char **s2)
{
	char	*without_leaks;

	without_leaks = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (!*s1 && *s2)
	{
		without_leaks = *s2;
		*s2 = NULL;
	}
	else if (!*s2 && *s1)
	{
		without_leaks = *s1;
		*s1 = NULL;
	}
	else
	{
		without_leaks = ft_strjoin(*s1, *s2);
		ft_strdel(s1);
		ft_strdel(s2);
	}
	return (without_leaks);
}
/*
**Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
**result of the concatenation of s1 and s2.
**If the allocation fails the function returns NULL.
**Param. #1 The prefix string.
**Param. #2 The su x string.
**Return value The “fresh” string result of the concatenation of the 2 strings.
**There aren't leaks.
*/

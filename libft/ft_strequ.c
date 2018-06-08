/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:35:55 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/25 18:15:11 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int x;

	x = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x])
		{
			x++;
		}
		if (s2[x] == '\0' && s1[x] == '\0')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
/*
**Lexicographical comparison between s1 and s2.
**If the 2 strings are identical the function returns 1, or 0 otherwise.
**Param. #1 The first string to be compared.
**Param. #2 The second string to be compared.
**Return value 1 or 0 according to if the 2 strings are identical or not.
*/

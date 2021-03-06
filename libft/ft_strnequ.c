/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:15:02 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/25 18:35:56 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x] && x < n)
		{
			x++;
		}
		if ((s2[x] == '\0' && s1[x] == '\0') || (x == n))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
/*
**Lexicographical comparison between s1 and s2 up to n
**characters or until a ’\0’ is reached.
**If the 2 strings are identical, the function returns 1, or 0 otherwise.
**Param. #1 The first string to be compared.
**Param. #2 The second string to be compared.
**The maximum number of characters to be compared.
**Return value 1 or 0 according to if the 2 strings are identical or not.
*/

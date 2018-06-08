/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:49:39 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/14 15:49:42 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	chk;

	i = 0;
	chk = 0;
	if (little[0] == '\0')
		return ((char *)big);
	else
	{
		while (big[i] != '\0' && i < n)
		{
			while (big[i] == little[chk] && i < n && little[chk] && big[i])
			{
				i++;
				chk++;
			}
			if (chk == ft_strlen(little))
			{
				return ((char *)(big + i - chk));
			}
			i = i - chk + 1;
			chk = 0;
		}
		return (NULL);
	}
}
/*
**The strstr() function locates the first occurrence of the null-terminated
**string little in the null-terminated string big.
**The strnstr() function locates the first occurrence of the null-terminated
**string little in the string big, where not more than n
**characters are searched.  Characters that appear after a `\0'
**character are not searched. Since the strnstr() function is a FreeBSD
**specific API, it should only be used when portability is not a concern.
**If little is an empty string, big is returned; if little occurs
**nowhere in big, NULL is returned; otherwise a pointer to the first
**character of the first occurrence of little is returned.
*/

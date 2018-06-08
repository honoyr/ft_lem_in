/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:55:01 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/02 20:55:03 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static	int		ft_count_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static	char	*ft_strsub_f(char const *s, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!s || len < 1)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > i)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		n;
	int		x;

	i = 0;
	x = 0;
	if (!s || !c)
		return (NULL);
	n = ft_count_word(s, c);
	if (!(ptr = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (n >= i && *s)
	{
		if (*s != c && *s != '\0')
			*(ptr + x++) = ft_strsub_f(s, ft_count_len(s, c));
		while (*s != c && *s != '\0')
			s++;
		i++;
		while (*s == c && *s != '\0')
			s++;
	}
	ptr[n] = NULL;
	return (ptr);
}
/*
**Description Allocates (with malloc(3)) and returns an array of
**“fresh” strings (all ending with ’\0’, including the array itself)
**obtained by spliting s using the character c as a delimiter.
**If the allocation fails the function returns NULL.
**Example : ft_strsplit("*hello*fellow***students*", ’*’)
**returns the array ["hello", "fellow", "students"].
**Param. #1 The string to split.
**Param. #2 The delimiter character.
**Return value The array of “fresh” strings result of the split.
*/

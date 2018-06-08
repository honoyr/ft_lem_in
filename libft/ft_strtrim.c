/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:26:50 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/29 20:26:52 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	start = 0;
	if (s != NULL)
	{
		end = ft_strlen(s) - 1;
		while (s[start] != '\0' && ft_whitespaces(s[start]) == 1)
			start++;
		if (start == end + 1)
			return (ft_strnew(0));
		else
		{
			while (end > 0 && ft_whitespaces(s[end]) == 1)
				end--;
			return (ft_strsub(s, start, (end - start + 1)));
		}
	}
	else
		return (NULL);
}
/*
**Ф-я пропускает ’ ’, ’\n’,’\t’ в начале и в конце строки
**return = копию на новую строку выделеную malloc.
**Если строка пустая или состоит из ’ ’, ’\n’,’\t’
**return = очищеную копию на новую строку выделеную malloc
**Allocates (with malloc(3)) and returns a copy of the
**string given as argument without whitespaces at the beginning
**or at the end of the string. Will be considered as whitespaces
**the following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces
**at the beginning or at the end, the function returns a copy of s.
**If the allocation fails the function returns NULL.
**Param. #1 The string to be trimed.
**Return value The “fresh” trimmed string or a copy of s.
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:54:25 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/23 21:12:20 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_s;

	i = 0;
	new_s = NULL;
	if (s && f)
	{
		new_s = (char *)malloc(sizeof(char) * ((ft_strlen(s)) + 1));
		if (new_s != NULL)
		{
			while (s[i] != '\0')
			{
				new_s[i] = f(s[i]);
				i++;
			}
			new_s[i] = '\0';
		}
	}
	return (new_s);
}
/*
**Ф-я передает каждый элемент s[i] как аргумент в другую ф-ю.
**void (*f)(char) - выполняет необходимые манипуляции над s[i].
**Выделяем malloc память под новый стринг и записываем результат манипуляций
**над каждым s[i]  элементом, возвращеемым f.
**Applies the function f to each character of the string given
**as argument to create a “fresh” new string (with malloc(3))
**resulting from the successive applications of f.
**Param. #1 The string to map.
**Param. #2 The function to apply to each character of s.
**Return value The “fresh” string created from the successive applications of f.
**Libc functions - malloc(3)
*/

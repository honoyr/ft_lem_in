/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:41:39 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/22 21:17:28 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char*)ft_memalloc(size + 1);
	if (new != NULL)
	{
		ft_bzero(new, size + 1);
		return (new);
	}
	else
		return (NULL);
}
/*
**Ф-я заполняет стринг \0 и возвращает очищеную память.
**Для чего это я так и не понял.
**Allocates (with malloc(3)) and returns a “fresh”
**string end- ing with ’\0’. Each character of the string
**is initialized at ’\0’. If the allocation fails the function returns NULL.
**The string allocated and initialized to 0.
*/

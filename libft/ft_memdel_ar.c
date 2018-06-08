/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_ar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:15:00 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/11 13:15:06 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel_ar(void **ar, size_t n)
{
	char	**s;
	size_t	i;

	i = 0;
	s = NULL;
	if (ar)
	{
		s = (char **)ar;
		while (i < n)
		{
			ft_memdel((void **)&s[i]);
			i++;
		}
		ft_memdel((void **)&ar);
	}
}
/*
**Чистит двумерный масив.
** The function clear the multidimensional arrays
*/

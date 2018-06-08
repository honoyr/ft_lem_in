/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_arlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:31:51 by dgonor            #+#    #+#             */
/*   Updated: 2018/01/11 18:32:00 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel_arlen(void **ar)
{
	char	**s;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	s = NULL;
	if (ar)
	{
		s = (char **)ar;
		while (ar[n] != NULL)
			n++;
		while (i < n)
		{
			ft_memdel((void **)&s[i]);
			i++;
		}
		ft_memdel((void **)&ar);
	}
}
/*
**Чистит двумерный масив без размера.
** The function clear the multidimensional arrays without size
*/

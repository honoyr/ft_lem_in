/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:33:37 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/22 20:41:54 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free((*(char**)ap));
		*((char**)ap) = NULL;
	}
	return ;
}
/*
**Ф-я берет как параметр адрес в массиве и освобождает память.
**После, по адресу осбобожденной памяти присвоить NULL.
**Takes as a parameter the address of a memory area
**that needs to be freed with free(3),
**then puts the pointer to NULL.
**A pointer’s address that needs its
**memory freed and set to NULL
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 21:17:16 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/22 21:47:03 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}
/*
**Ф-я берет как параметр адрес и освобождает память ф-й free
**После, по адресу осбобожденной памяти присвоивается NULL.
**Takes as a parameter the address of
**a string that need to be freed with free(3), then sets its pointer to NULL.
**The string’s address that needs to be freed and its pointer set to NULL.
*/

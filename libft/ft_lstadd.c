/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:07:31 by dgonor            #+#    #+#             */
/*   Updated: 2017/12/06 21:07:33 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
/*
**Description - Adds the element new at the beginning of the list.
**Param. #1 The address of a pointer to the first link of a list.
**Param. #2 The link to add at the beginning of the list.
**Return value - None.
**Libc functions -None
*/

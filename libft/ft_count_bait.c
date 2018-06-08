/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:55:31 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/21 16:55:33 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_count_bait(unsigned int nbit)
{
	int			baits;

	baits = 0;
	if (nbit <= 7)
		baits += 1;
	else if (nbit <= 11)
		baits += 2;
	else if (nbit <= 16)
		baits += 3;
	else
		baits += 4;
	return (baits);
}

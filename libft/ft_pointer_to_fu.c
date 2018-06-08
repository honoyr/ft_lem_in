/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_pointer_to_fu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:19:55 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/22 14:19:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pointer_to_fu(void)
{
	g_fun['i'] = &type_i;
	g_fun['d'] = &type_i;
	g_fun['D'] = &type_i;
	g_fun['c'] = &type_c;
	g_fun['C'] = &type_cu;
	g_fun['s'] = &type_s;
	g_fun['S'] = &type_su;
	g_fun['u'] = &type_u;
	g_fun['U'] = &type_u;
	g_fun['x'] = &type_x;
	g_fun['X'] = &type_x;
	g_fun['O'] = &type_o;
	g_fun['o'] = &type_o;
	g_fun['p'] = &type_p;
}

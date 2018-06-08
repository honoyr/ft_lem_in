/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 20:15:07 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/22 20:15:10 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		data_mod_u(va_list arg, t_format *fl)
{
	unsigned long long	mod;

	mod = 0;
	if (fl->type == 'U' || fl->type == 'O')
		mod = (unsigned long long)va_arg(arg, unsigned long);
	else if (fl->z == 1)
		mod = (unsigned long long)va_arg(arg, size_t);
	else if (fl->j == 1)
		mod = (unsigned long long)va_arg(arg, uintmax_t);
	else if (fl->ll == 1)
		mod = va_arg(arg, unsigned long long);
	else if (fl->l == 1)
		mod = (unsigned long long)va_arg(arg, unsigned long);
	else if (fl->h == 1)
		mod = (unsigned long long)(unsigned short)va_arg(arg, int);
	else if (fl->hh == 1)
		mod = (unsigned long long)(unsigned char)va_arg(arg, int);
	else
		mod = (unsigned long long)va_arg(arg, unsigned int);
	return (mod);
}

long long				data_mod(va_list arg, t_format *fl)
{
	long long			mod;

	mod = 0;
	if (fl->type == 'D')
		mod = (long long)va_arg(arg, long);
	else if (fl->z == 1)
		mod = (long long)va_arg(arg, size_t);
	else if (fl->j == 1)
		mod = (long long)va_arg(arg, uintmax_t);
	else if (fl->ll == 1)
		mod = va_arg(arg, long long);
	else if (fl->l == 1)
		mod = (long long)va_arg(arg, long);
	else if (fl->h == 1)
		mod = (long long)(short int)va_arg(arg, int);
	else if (fl->hh == 1)
		mod = (long long)(signed char)va_arg(arg, int);
	else
		mod = (long long)va_arg(arg, int);
	return (mod);
}

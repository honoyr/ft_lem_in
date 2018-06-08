/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:51:17 by dgonor            #+#    #+#             */
/*   Updated: 2018/03/05 16:51:23 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	int		res;
	int		i;

	res = 0;
	i = -1;
	ft_pointer_to_fu();
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%' && !(ft_strequ(format, "% ")))
			res += ft_pars_printf((format + (i += 1)), &i, &arg);
		if (!format[i])
			break ;
		if (format[i] == '%' && !(ft_strequ(format, "% ")))
		{
			i--;
			continue ;
		}
		write(1, &format[i], 1);
		res++;
	}
	va_end(arg);
	return (res);
}

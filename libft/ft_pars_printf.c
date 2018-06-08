/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:26:11 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/22 14:26:13 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_set_format(t_format *fl)
{
	ft_memset(fl->flags, 0, 5);
	fl->width = -1;
	fl->precision = -1;
	fl->mod = -1;
	fl->type = 'u';
	fl->bait = 0;
	fl->hh = 0;
	fl->h = 0;
	fl->ll = 0;
	fl->l = 0;
	fl->j = 0;
	fl->z = 0;
	return (0);
}

static void			ft_help_precision(const char *format, int *p, t_format *fl)
{
	int		i;

	i = 0;
	ft_set_precision(&format[i], fl);
	i++;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	*p += i;
}

static int			ft_set_type(const char *pos, t_format *fl, va_list *arg)
{
	int			i;
	int			c;

	i = 0;
	if (ft_strchr(TYPE, pos[i]))
	{
		fl->type = pos[i];
		c = pos[i];
		return (g_fun[c](*arg, fl));
	}
	else
	{
		fl->type = pos[i];
		return (type_und(fl));
	}
}

int					ft_pars_printf(const char *format, int *p, va_list *arg)
{
	t_format	fl;
	int			i;
	int			res;
	int			n;

	res = 0;
	n = 0;
	i = ft_set_format(&fl);
	while (format[i])
	{
		while (ft_strchr(FLAG, format[i]))
			i += ft_set_flags(&format[i], &fl);
		if (format[i] >= '0' && format[i] <= '9')
			i += ft_set_width(&format[i], &fl);
		if (format[i] == '.')
			ft_help_precision(&format[i], &i, &fl);
		if (ft_strchr("hljz", format[i]))
			i += ft_set_mod(&format[i], &fl, &n);
		if (!(ft_strchr(MOD, format[i])))
		{
			*p += i + 1;
			return (ft_set_type(&format[i], &fl, arg));
		}
	}
	return (res);
}

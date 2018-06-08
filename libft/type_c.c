/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:35:47 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/03 14:35:49 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*type_help_c(t_format *fl, char *src)
{
	char				*r;
	char				*s1;
	char				*s2;

	r = NULL;
	if (fl->flags[2])
		fl->flags[1] = 0;
	if (fl->flags[1] && fl->precision == -1 && fl->width >= 0)
	{
		s1 = ft_strzero(fl->width > 1 ? fl->width - 1 : 0);
		s2 = ft_strsub(src, 0, 1);
		r = ft_strljoin(&s1, &s2);
	}
	else if (fl->flags[1] && fl->precision >= 0)
	{
		s1 = ft_strzero(fl->width - 1 <= 0 ? 0 : fl->width - 1);
		s2 = ft_strsub(src, 0, 1);
		r = ft_strljoin(&s1, &s2);
	}
	else
		r = ft_strsub(src, 0, 1);
	return (r);
}

int						type_c(va_list arg, t_format *fl)
{
	unsigned char		c;
	char				*src;
	char				*s;
	int					l;
	int					x;

	x = 0;
	s = NULL;
	src = NULL;
	if (fl->l == 1)
		return (type_cu(arg, fl));
	c = (unsigned char)va_arg(arg, int);
	src = ft_strnew(1);
	src[0] = c;
	s = type_help_c(fl, src);
	l = ft_strlen(s);
	if (!c)
		l += 1;
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	free(src);
	return (l + x);
}

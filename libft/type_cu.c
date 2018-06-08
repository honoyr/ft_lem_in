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

static char			*type_str_uni(t_format *fl, char *src)
{
	char			*r;
	char			*s1;
	char			*s2;

	r = NULL;
	s1 = NULL;
	s2 = NULL;
	if (fl->flags[1] && fl->precision >= 0)
	{
		s1 = ft_strzero(WIDTH - PRES <= 0 ? 0 : WIDTH - fl->bait);
		s2 = ft_strsub(src, 0, fl->bait);
		r = ft_strljoin(&s1, &s2);
	}
	else
		r = ft_strsub(src, 0, fl->bait);
	return (r);
}

static char			*type_help_uni(t_format *fl, char *src)
{
	char			*r;
	char			*s1;
	char			*s2;

	r = NULL;
	s1 = NULL;
	s2 = NULL;
	if (fl->flags[2])
		fl->flags[1] = 0;
	if (fl->flags[1] && fl->precision == -1 && fl->width >= 0)
	{
		s1 = ft_strzero(fl->width > fl->bait ? fl->width - fl->bait : 0);
		s2 = ft_strsub(src, 0, fl->bait);
		r = ft_strljoin(&s1, &s2);
	}
	else if (fl->flags[1] && fl->precision >= 0 && fl->width >= 0)
	{
		s1 = ft_strzero(fl->width - fl->bait <= 0 ? 0 : fl->width - fl->bait);
		s2 = ft_strsub(src, 0, fl->bait);
		r = ft_strljoin(&s1, &s2);
	}
	else
		return (type_str_uni(fl, src));
	return (r);
}

int					type_cu(va_list arg, t_format *fl)
{
	int				l;
	int				x;
	char			*s;
	char			*tmp;
	unsigned int	n;

	x = 0;
	tmp = NULL;
	if (MB_CUR_MAX > 1)
	{
		n = va_arg(arg, wint_t);
		tmp = ft_print_unic(n, fl);
	}
	else
		return (type_c(arg, fl));
	s = type_help_uni(fl, tmp);
	l = ft_strlen(s);
	if (!n)
		l += 1;
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	if (tmp)
		free(tmp);
	return (l + x);
}

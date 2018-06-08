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

static int			ft_precisin_su(t_format *fl, wchar_t *wsrc)
{
	int			bait;
	int			pres;
	int			tmp;

	tmp = 0;
	bait = 0;
	pres = 0;
	pres = fl->precision;
	while (*wsrc && (pres - ft_count_bait(count_nbr_base(*wsrc, 2)) >= 0))
	{
		tmp = ft_count_bait(count_nbr_base(*wsrc, 2));
		bait += tmp;
		wsrc++;
		pres -= tmp;
	}
	return (bait);
}

static char			*ft_stru(t_format *fl, char *src, wchar_t *wsrc)
{
	char		*r;
	char		*s1;
	char		*s2;
	int			lenbait;

	lenbait = 0;
	lenbait = ft_precisin_su(fl, wsrc);
	if (fl->flags[1] && fl->precision == -1 && fl->width >= 0)
	{
		s1 = ft_strzero(WIDTH > LENSTR ? WIDTH - LENSTR : 0);
		s2 = ft_strsub(src, 0, ft_strlen(src));
		r = ft_strljoin(&s1, &s2);
	}
	else if (fl->flags[1] && fl->precision >= 0)
	{
		s1 = ft_strzero(fl->width - lenbait <= 0 ? 0 : fl->width - lenbait);
		s2 = ft_strsub(src, 0, lenbait);
		r = ft_strljoin(&s1, &s2);
	}
	else if (fl->precision >= 0)
		r = ft_strsub(src, 0, lenbait);
	else
		r = ft_strsub(src, 0, ft_strlen(src));
	return (r);
}

static char			*type_help_su(t_format *fl, char *src, wchar_t *wsrc)
{
	char		*r;

	r = NULL;
	if (fl->flags[2])
		fl->flags[1] = 0;
	if (ft_strequ(src, "(null)"))
		r = ft_strsub("(null)", 0, fl->precision == -1 ? 6 : fl->precision);
	else
		r = ft_stru(fl, src, wsrc);
	return (r);
}

static char			*ft_strunicode(wchar_t *src, t_format *fl)
{
	char		*str;
	char		*s1;

	str = ft_print_unic(*src, fl);
	while (*src++)
	{
		s1 = ft_print_unic(*src, fl);
		str = ft_strljoin(&str, &s1);
	}
	return (str);
}

int					type_su(va_list arg, t_format *fl)
{
	int			l;
	wchar_t		*src;
	char		*dst;
	char		*tmp;
	int			x;

	x = 0;
	dst = NULL;
	src = NULL;
	tmp = NULL;
	src = va_arg(arg, wchar_t*);
	if (src == NULL)
		tmp = ft_strdup("(null)");
	else if (!ft_strequ(tmp, "(null)"))
		tmp = ft_strunicode(src, fl);
	dst = type_help_su(fl, tmp, src);
	l = ft_strlen(dst);
	fl->flags[2] != 0 ? write(1, dst, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, dst, l) : ft_width_pr(&x, fl->width - l, ' ');
	if (tmp != NULL)
		free(tmp);
	if (dst != NULL)
		free(dst);
	return (l + x);
}

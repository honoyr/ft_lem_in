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

char				*ft_strzero(int l)
{
	char		*res;

	res = NULL;
	if (l < 0)
		l = 0;
	if (!(res = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = '0';
	}
	return (res);
}

static char			*type_help_s(t_format *fl, char *src)
{
	char		*r;
	char		*s1;
	char		*s2;

	r = NULL;
	if (fl->flags[2])
		fl->flags[1] = 0;
	if (fl->flags[1] && fl->precision == -1 && fl->width >= 0)
	{
		s1 = ft_strzero(WIDTH > LENSTR ? WIDTH - LENSTR : 0);
		s2 = ft_strsub(src, 0, ft_strlen(src));
		r = ft_strljoin(&s1, &s2);
	}
	else if (fl->flags[1] && fl->precision >= 0)
	{
		s1 = ft_strzero(WIDTH - fl->precision <= 0 ? 0 : WIDTH - fl->precision);
		s2 = ft_strsub(src, 0, fl->precision);
		r = ft_strljoin(&s1, &s2);
	}
	else
		r = ft_strsub(src, 0, PRES == -1 ? ft_strlen(src) : PRES);
	return (r);
}

int					type_s(va_list arg, t_format *fl)
{
	char		*src;
	char		*dst;
	char		*tmp;
	int			l;
	int			x;

	x = 0;
	dst = NULL;
	tmp = NULL;
	if (fl->l == 1)
		return (type_su(arg, fl));
	src = va_arg(arg, char*);
	if (src == NULL)
		tmp = ft_strdup("(null)");
	dst = type_help_s(fl, src == NULL ? tmp : src);
	l = ft_strlen(dst);
	fl->flags[2] != 0 ? write(1, dst, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, dst, l) : ft_width_pr(&x, fl->width - l, ' ');
	if (tmp != NULL)
		free(tmp);
	if (dst != NULL)
		free(dst);
	return (l + x);
}

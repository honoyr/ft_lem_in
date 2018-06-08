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

static char		*type_help_und(t_format *fl, char s)
{
	char	*r;
	char	*s1;
	char	*s2;

	r = NULL;
	if (fl->flags[2])
		fl->flags[1] = 0;
	if (fl->flags[1] && fl->precision == -1 && fl->width >= 0)
	{
		s1 = ft_strzero(fl->width > 1 ? fl->width - 1 : 0);
		s2 = ft_strsub(&s, 0, 1);
		r = ft_strljoin(&s1, &s2);
	}
	else if (fl->flags[1] && fl->precision >= 0)
	{
		s1 = ft_strzero(fl->width - 1 <= 0 ? 0 : fl->width - 1);
		s2 = ft_strsub(&s, 0, 1);
		r = ft_strljoin(&s1, &s2);
	}
	else
		r = ft_strsub(&s, 0, 1);
	return (r);
}

int				type_und(t_format *fl)
{
	int		l;
	char	src;
	char	*dst;
	int		x;

	x = 0;
	src = fl->type;
	dst = type_help_und(fl, src);
	l = ft_strlen(dst);
	fl->flags[2] != 0 ? write(1, dst, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, dst, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(dst);
	return (l + x);
}

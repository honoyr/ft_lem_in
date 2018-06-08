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

static char		*ft_itoa_bx(t_llu n, int l, int ch, t_format *fl)
{
	int		i;
	char	*res;
	char	*c;

	c = fl->type == 'X' ? BASESTRBIG : BASESTR;
	i = count_nbr_base(n, 16);
	if (n == 0)
		ch = 0;
	l = i > l ? i : l;
	if (!(res = (char*)malloc((l += (ch == '#' ? 2 : 0)) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = c[n % 16];
		n /= 16;
	}
	if (ch == '#')
		res[1] = fl->type == 'X' ? 'X' : 'x';
	return (res);
}

int				type_x(va_list arg, t_format *fl)
{
	int			l;
	t_llu		n;
	char		*s;
	int			x;

	x = 0;
	s = NULL;
	n = data_mod_u(arg, fl);
	if (fl->precision == -1 && fl->flags[1] && !fl->flags[2])
	{
		if (fl->flags[0])
			s = ft_itoa_bx(n, fl->width - 2, fl->flags[0], fl);
		else
			s = ft_itoa_bx(n, fl->width, fl->flags[0] ? '#' : 0, fl);
	}
	else
		s = ft_itoa_bx(n, fl->precision, fl->flags[0] ? '#' : 0, fl);
	if (!fl->precision && !n)
		s[ft_strlen(s) - 1] = fl->width > 0 ? ' ' : 0;
	l = ft_strlen(s);
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	return (l + x);
}

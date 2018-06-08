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

int					count_nbr_base(size_t n, int base)
{
	int	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

static char			*ft_itoa_b(t_llu n, int l, int ch, t_format *fl)
{
	int		i;
	char	*res;

	i = count_nbr_base(n, 8);
	if (!fl->flags[0])
		ch = 0;
	else if (n == 0 && !(fl->precision == 0))
		ch = 0;
	l = i > l ? i : l;
	if (!(res = (char*)malloc((l += (ch == '#' ? 1 : 0)) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = BASESTR[n % 8];
		n /= 8;
	}
	if (ch)
		res[0] = '0';
	return (res);
}

static char			*type_help_o(t_format *fl, size_t n)
{
	char		*s;

	s = NULL;
	if (fl->flags[0] && n != 0)
		s = ft_itoa_b(n, fl->precision - 1, fl->flags[0] ? '#' : 0, fl);
	else
		s = ft_itoa_b(n, fl->precision, fl->flags[0] ? '#' : 0, fl);
	return (s);
}

int					type_o(va_list arg, t_format *fl)
{
	char		*s;
	t_llu		n;
	int			l;
	int			x;

	x = 0;
	s = NULL;
	n = data_mod_u(arg, fl);
	if (fl->precision == -1 && fl->flags[1] && !fl->flags[2])
	{
		if (fl->flags[0])
			s = ft_itoa_b(n, fl->width - 1, fl->flags[0], fl);
		else
			s = ft_itoa_b(n, fl->width, fl->flags[0] ? '#' : 0, fl);
	}
	else
		s = type_help_o(fl, n);
	if (!fl->precision && !n)
		s[ft_strlen(s) - 1] = fl->width > 0 ? ' ' : 0;
	l = ft_strlen(s);
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	return (l + x);
}

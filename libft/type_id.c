/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:52:17 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/22 12:52:19 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_itoapf_m(size_t n, int l)
{
	char		*res;

	l = l < count_nbr(n) ? count_nbr(n) : l;
	if (!(res = (char*)malloc((l += 1) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = (n % 10) + '0';
		n /= 10;
	}
	res[0] = '-';
	return (res);
}

static char			*ft_itoapf(long long int n, int l, int ch)
{
	int			i;
	char		*res;

	i = count_nbr(n);
	l = l < i ? i : l;
	if (n < 0)
		return (ft_itoapf_m(-n, l));
	if (!(res = (char*)malloc((l += (ch > 0 ? 1 : 0)) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = (n % 10) + '0';
		n /= 10;
	}
	if (ch)
		res[0] = ch;
	return (res);
}

int					type_i(va_list arg, t_format *fl)
{
	int			l;
	long long	n;
	char		*s;
	int			x;

	x = 0;
	s = NULL;
	n = data_mod(arg, fl);
	if (fl->precision == -1 && fl->flags[1] && !fl->flags[2])
	{
		if (fl->flags[3] || n < 0 || fl->flags[4])
			s = ft_itoapf(n, fl->width - 1, fl->flags[4] ? '+' : fl->flags[3]);
		else
			s = ft_itoapf(n, fl->width, fl->flags[4] ? '+' : fl->flags[3]);
	}
	else
		s = ft_itoapf(n, fl->precision, fl->flags[4] ? '+' : fl->flags[3]);
	if (!fl->precision && !n)
		s[ft_strlen(s) - 1] = fl->width > 0 ? ' ' : 0;
	l = ft_strlen(s);
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	return (l + x);
}

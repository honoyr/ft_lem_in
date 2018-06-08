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

static int					count_nbr_u(unsigned long long n)
{
	int						i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char						*ft_itoa_u(t_llu n, int l, int ch)
{
	int						i;
	char					*res;

	i = count_nbr_u(n);
	l = l < i ? i : l;
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

int							type_u(va_list arg, t_format *fl)
{
	int						l;
	t_llu					n;
	char					*s;
	int						x;

	x = 0;
	s = NULL;
	n = data_mod_u(arg, fl);
	if (fl->precision == -1 && fl->flags[1] && !fl->flags[2])
	{
		if (fl->flags[3] || fl->flags[4])
			s = ft_itoa_u(n, fl->width - 1, 0);
		else
			s = ft_itoa_u(n, fl->width, 0);
	}
	else
		s = ft_itoa_u(n, fl->precision, 0);
	if (!fl->precision && !n)
		s[ft_strlen(s) - 1] = fl->width > 0 ? ' ' : 0;
	l = ft_strlen(s);
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	return (l + x);
}

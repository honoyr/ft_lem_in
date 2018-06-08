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

static char			*ft_itoa_bp(size_t n, int l)
{
	int			i;
	char		*res;

	i = count_nbr_base(n, 16);
	l = i > l ? i : l;
	if (!(res = (char*)malloc((l += 2) + 1)))
		return (NULL);
	res[l] = 0;
	while (l != 0)
	{
		res[--l] = BASESTR[n % 16];
		n /= 16;
	}
	res[1] = 'x';
	return (res);
}

int					type_p(va_list arg, t_format *fl)
{
	int			l;
	size_t		n;
	char		*s;
	int			x;

	x = 0;
	s = NULL;
	n = (size_t)va_arg(arg, void*);
	if (fl->precision == -1 && fl->flags[1] && !fl->flags[2])
		s = ft_itoa_bp(n, fl->width - 2);
	else
		s = ft_itoa_bp(n, fl->precision);
	if (!fl->precision && !n)
		s[ft_strlen(s) - 1] = 0;
	l = ft_strlen(s);
	fl->flags[2] != 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	fl->flags[2] == 0 ? write(1, s, l) : ft_width_pr(&x, fl->width - l, ' ');
	free(s);
	return (l + x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:26:50 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/21 16:27:00 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_4bit(char *s, unsigned int v, t_format *fl)
{
	s[0] = (char)(240 | (v >> 18));
	s[1] = (char)(128 | ((v >> 12) & 63));
	s[2] = (char)(128 | ((v >> 6) & 63));
	s[3] = (char)(128 | (v & 63));
	fl->bait += 4;
}

static void		ft_print_3bit(char *s, unsigned int v, t_format *fl)
{
	s[0] = (char)(224 | (v >> 12));
	s[1] = (char)(128 | ((v >> 6) & 63));
	s[2] = (char)(128 | ((v & 63)));
	fl->bait += 3;
}

static void		ft_print_2bit(char *s, unsigned int v, t_format *fl)
{
	s[0] = (char)(192 | (v >> 6));
	s[1] = (char)(128 | (v & 63));
	fl->bait += 2;
}

char			*ft_print_unic(unsigned int n, t_format *fl)
{
	char			*src;
	unsigned int	v;
	int				size;

	v = n;
	size = count_nbr_base(n, 2);
	src = ft_strnew(4);
	if (size <= 7)
	{
		src[0] = n;
		fl->bait += 1;
	}
	else if (size <= 11)
		ft_print_2bit(src, v, fl);
	else if (size <= 16)
		ft_print_3bit(src, v, fl);
	else
		ft_print_4bit(src, v, fl);
	return (src);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:36:11 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/22 15:36:13 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_set_precision(const char *pos, t_format *fl)
{
	if (*pos == '.')
	{
		pos++;
		if (*pos == ' ' || ft_strchr("%sSpdDioOuUxXcC", *pos))
			fl->precision = 0;
		if (ft_isdigit(*pos) || *pos == '-')
			fl->precision = ft_atoi(pos);
	}
}

void		ft_help_set_mod(const char *pos, t_format *fl, int *n)
{
	if (*n % 2 == 0 && (*pos == 'h' || *pos == 'l'))
	{
		fl->hh = *pos == 'h' ? 1 : 0;
		fl->ll = *pos == 'l' ? 1 : 0;
		fl->h = 0;
		fl->l = 0;
	}
	else if (*pos == 'h' || *pos == 'l')
	{
		fl->h = *pos == 'h' ? 1 : 0;
		fl->l = *pos == 'l' ? 1 : 0;
		fl->hh = 0;
		fl->ll = 0;
	}
	return ;
}

int			ft_set_mod(const char *pos, t_format *fl, int *n)
{
	int		i;

	i = 0;
	while (*pos == 'h' || *pos == 'l')
	{
		i++;
		pos++;
		*n += 1;
	}
	if (*pos == 'j' || *pos == 'z')
	{
		fl->z = *pos == 'z' ? 1 : 0;
		fl->j = *pos == 'j' ? 1 : 0;
		i++;
		n += 1;
	}
	pos--;
	ft_help_set_mod(pos, fl, n);
	return (i);
}

int			ft_set_width(const char *pos, t_format *fl)
{
	int		i;

	i = 0;
	if (ft_isdigit(*pos))
	{
		fl->width = ft_atoi(pos);
		i = ft_countsize(fl->width);
	}
	else
		i++;
	return (i);
}

int			ft_set_flags(const char *pos, t_format *fl)
{
	int		i;

	i = 0;
	if (*pos == '#')
		fl->flags[0] = '#';
	if (*pos == '0' && !fl->flags[1])
		fl->flags[1] = '0';
	if (*pos == ' ' && !fl->flags[3])
		fl->flags[3] = ' ';
	if (*pos == '+')
	{
		fl->flags[4] = '+';
		fl->flags[3] = 0;
	}
	if (*pos == '-')
	{
		fl->flags[2] = '-';
		fl->flags[1] = 0;
	}
	i++;
	return (i);
}

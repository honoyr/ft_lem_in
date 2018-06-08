/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:50:09 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/22 15:50:12 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <locale.h>
# define FLAG "#0 +-"
# define MOD "0123456789.-+ #hljz"
# define TYPE "sSpdDioOuUxXcC"
# define WIDTH fl->width
# define PRES fl->precision
# define LENSTR (int)ft_strlen(src)
# define BASESTR "0123456789abcdef"
# define BASESTRBIG "0123456789ABCDEF"

/*
**flags:
**		0: '#'
**		1: '0'
**		2: '-'
** 		3: ' '
** 		4: '+'
**width:
** 		number >= 0
**precision:
** 		.' '  haven't any number = 0 | .' ' =||= .0
**mod:
** 		hh == 0
**		h == 1
**		l == 2
**		ll == 3
**		j == 4
**		z == 5
**type:
**		"%sSpdDioOuUxXcC"
*/

typedef	struct	s_format
{
	char		flags[5];
	int			width;
	int			precision;
	int			mod;
	int			hh;
	int			h;
	int			ll;
	int			l;
	int			j;
	int			z;
	char		type;
	int			bait;
}				t_format;

typedef	unsigned long long t_llu;

int				(*g_fun[127])(va_list arg, t_format *fl);
void			ft_pointer_to_fu(void);
int				ft_printf(const char *format, ...);
int				ft_pars_printf(const char *format, int *p, va_list *arg);

void			ft_set_precision(const char *pos, t_format *fl);
int				ft_set_mod(const char *pos, t_format *fl, int *n);
int				ft_set_width(const char *pos, t_format *fl);
void			ft_width_pr(int *i, int len, char c);
int				ft_set_flags(const char *pos, t_format *fl);

int				type_i(va_list arg, t_format *fl);
int				type_u(va_list arg, t_format *fl);
int				type_o(va_list arg, t_format *fl);
int				type_x(va_list arg, t_format *fl);
int				type_c(va_list arg, t_format *fl);
int				type_cu(va_list arg, t_format *fl);
int				type_s(va_list arg, t_format *fl);
int				type_su(va_list arg, t_format *fl);
int				type_p(va_list arg, t_format *fl);
int				type_und(t_format *fl);

t_llu			data_mod_u(va_list arg, t_format *fl);
long long		data_mod(va_list arg, t_format *fl);

char			*ft_strzero(int l);
char			*ft_print_unic(unsigned int n, t_format *fl);
int				ft_count_bait(unsigned int nbit);
int				count_nbr_base(size_t n, int base);
#endif

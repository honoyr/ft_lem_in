/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:48:24 by exam              #+#    #+#             */
/*   Updated: 2018/04/17 13:45:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lenn(int tmp, int base)
{
	int		i;

	i = 0;
	if (tmp <= 0)
		i++;
	while (tmp != 0)
	{
		tmp /= base;
		i++;
	}
	return (i);
}

void	ft_help(char *s, int val, int base, int len)
{
	char	*c;

	c = "0123456789ABCDEF";
	if (val < 0 && base == 10)
	{
		if (val == -2147483648)
		{
			s[--len] = '8';
			val = 214748364;
		}
		else
			val *= -1;
		s[0] = '-';
	}
	if (val == 0)
		s[--len] = '0';
	while (val)
	{
		s[--len] = c[val % base];
		val /= base;
	}
}

char	*ft_itoa_base(int val, int base)
{
	int		len;
	char	*str;

	len = lenn(val, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	ft_help(str, val, base, len);
	return (str);
}

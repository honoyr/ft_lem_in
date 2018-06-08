/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:26:11 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/18 19:26:13 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str)
{
	int				i;
	unsigned long	p;
	long long		flag;

	i = 0;
	p = 0;
	flag = 1;
	while (ft_isspace(str[i]) == 1 && str[i] != '\0')
		i++;
	if ((ft_isdigit(str[i + 1]) == 1) && (str[i] == '-' || str[i] == '+'))
	{
		flag = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		p = p * 10 + (str[i] - '0');
		i++;
	}
	if (p >= 9223372036854775807 && flag == 1)
		return (-1);
	else if (p > 9223372036854775807 && flag == -1)
		return (0);
	else
		return ((long long)(flag * p));
}
/*
**The atoi() function converts the initial portion
**of the string pointed to by str to int representation.
**It is equivalent to:(int)strtol(str, (char **)NULL, 10);
**While the atoi() function uses the current
**locale, the atoi_l() function may be passed a
**locale directly.
**The atoi() and atoi_l() functions are threadsafe
**and async-cancel-safe.
**The strtol() and strtol_l() functions are
**recommended instead of atoi() and atoi_l()
**functions, especially in new code.
*/

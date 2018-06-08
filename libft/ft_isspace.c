/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:46:56 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/18 21:46:58 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}
/*
**The isspace() function tests for the
**white-space characters.  For any
**locale, this includes the following
**standard characters:
**The isspace() function returns zero
**if the character tests false and
**returns non-zero if the character tests true.
*/

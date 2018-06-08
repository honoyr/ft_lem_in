/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:39:36 by dgonor            #+#    #+#             */
/*   Updated: 2017/10/28 21:33:20 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0'
		&& ((unsigned char)s1[x] == (unsigned char)s2[x]))
	{
		x++;
	}
	return ((int)((unsigned char)s1[x] - (unsigned char)s2[x]));
}
/*
**The strcmp() and strncmp() functions lexicographically compare the
**null-terminated strings s1 and s2.
**The strcmp() and strncmp() functions return an integer greater than,
**equal to, or less than 0, according as the string s1 is greater
**than, equal to, or less than the string s2.  The comparison is done
**using unsigned characters, so that `\200' is greater than `\0'.
*/

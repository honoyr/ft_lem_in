/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:25:38 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/08 21:21:27 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int					i;
	unsigned int		size;

	i = 0;
	size = 0;
	while (s1[size] != '\0')
	{
		size++;
	}
	while (s2[i] != '\0')
	{
		s1[size] = s2[i];
		size++;
		i++;
	}
	s1[size] = '\0';
	return (s1);
}
/*
**The strcat() and strncat() functions append a copy of the
**null-terminated string s2 to the end of the null-terminated string s1,
**then add a terminating `\0'.  The string s1 must have
**sufficient space to hold the result.
**The source and destination strings should not
**overlap, as the behavior is undefined.
*/

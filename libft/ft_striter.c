/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:08:55 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/23 17:11:55 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(&s[i]);
			i++;
		}
	}
}
/*
**Ф-я передает каждый элемент s[i] как аргумент в другую ф-ю.
**void (*f)(char*) - выполняет необходимые манипуляции над s[i].
**Applies the function f to each character of the string passed as argument.
**Each character is passed by address to f to be modified if necessary.
**Param. #1 The string to iterate.
**Param. #2 The function to apply to each character of s.
*/

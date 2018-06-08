/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:19:28 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/23 17:53:43 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int		i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
**Ф-я передает каждый элемент s[i] как аргумент в другую ф-ю.
**А также index как перрвый аргумент.
**void (*f) (unsigned int, char *) - выполняет необходимые манипуляции над s[i].
**Applies the function f to each character of the string passed as argument,
**and passing its index as first argument. Each character is passed by
**address to f to be modified if necessary.
**Param. #1 The string to iterate.
**Param. #2 The function to apply to each character of s and its index.
*/

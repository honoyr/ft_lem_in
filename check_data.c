/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:22:59 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/23 16:23:02 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

char			**check_line(t_game *data, int flag, int c)
{
	int			i;
	char		**arr;

	i = -1;
	arr = NULL;
	if ((arr = ft_strsplit(data->line, c)))
	{
		while (arr[++i])
		{
			if (i < 3 && check_name(arr[i], data))
				break ;
			if (flag == 3 && i > 0 && check_coord(arr[i], data))
				break ;
		}
		if (i == flag && !data->error && *arr)
			return (arr);
	}
	data->error = 2;
	if (arr)
		ft_memdel_arlen((void**)arr);
	arr = NULL;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:30:22 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/23 17:30:25 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

int				check_int(char *ptr)
{
	int			j;
	int			i;

	j = 0;
	i = -1;
	if (ptr[0] = '0')
		return (1);
	while (ptr[++i])
	{
		if (ft_isdigit(ptr[i]))
			j++;
		j--;
	}
	if (j != 0)
		return (1);
	if (ft_strlen(ptr) > 10)
		return (1);
	if (ft_atoi(ptr) > 2147483647)
		return (1);
	return (0);
}

int				check_coord(char *coord, t_game *data)
{
	int			i;

	i = -1;
	while (coord[++i])
	{
		if (!ft_isdigit(coord[i]))
		{
			data->error = 7;
			return (0);
		}
	}
	return ((check_int(coord) ? 1 : 0));
}

int				check_name(char *name, t_game *data)
{
	int			i;

	i = -1;
	while (name[++i])
	{
		if (name[i] == ' ' || name[i] == '-' || name[i] == 'L')
		{
			data->error = 6;
			return (1);
		}
	}
	return (0);
}

void			valid_start_end(t_game *data)
{
	if (data->room)
	{
		if (!(data->room[data->end].link))
		{
			data->error = 15;
			error(data);
		}
		if (!(data->room[data->start].link))
		{
			data->error = 16;
			error(data);
		}
	}
}

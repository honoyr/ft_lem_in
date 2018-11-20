/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 19:47:27 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/22 19:47:30 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void			del_arr_rooms(t_game *data)
{
	int			i;

	i = 0;
	while (i < data->nroom)
	{
		if (data->room[i].link)
			lstdel_link(&data->room[i].link);
		if (data->room[i].ways)
			lstdel_list_way(&data->room[i].ways);
		i++;
	}
}

void			del_game(t_game *data)
{
	t_room		*tmp;

	tmp = NULL;
	if (data->visited)
		ft_strdel(&data->visited);
	if (data->way_v)
		ft_strdel(&data->way_v);
	while (data->list)
	{
		tmp = data->list;
		lstdel_room(&tmp);
		data->list = data->list->next;
	}
	if (data->room)
		del_arr_rooms(data);
	if (data->room)
	{
		free(data->room);
		data->room = NULL;
	}
}

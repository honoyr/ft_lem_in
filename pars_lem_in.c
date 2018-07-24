/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lem-in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:55:07 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/07 11:55:10 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void			valid_ant(t_game *data)
{
	char		*ptr;

	ptr = ft_strtrim(data->line);
	if (!check_int(ptr))
	{
		data->ants = ft_atoi(ptr);
		data->type = ROOM;
	}
	else
		data->error = 1;
	if (ptr)
		ft_strdel(&ptr);
}

void			create_list(t_game *data)
{
	t_room		*tmp;

	tmp = valid_data(data);
	if (!tmp)
		return ;
	if (!data->list)
		data->list = tmp;
	else if (data->list)
		lstback_list(&data->list, tmp, data);
	data->nroom++;
}

void			lstback_list(t_room **lst, t_room *add, t_game *data)
{
	t_room		*tmp;

	if (lst && add)
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			if ((ft_strequ(tmp->name, add->name))
				|| (tmp->x == add->x && tmp->y == add->y))
			{
				lstdel_room(&add);
				data->error = 8;
				return ;
			}
			tmp = tmp->next;
		}
		if ((ft_strequ(tmp->name, add->name))
			|| (tmp->x == add->x && tmp->y == add->y))
		{
			lstdel_room(&add);
			data->error = 8;
			return ;
		}
		tmp->next = add;
	}
}

t_room			*valid_data(t_game *data)
{
	t_room		*room;
	char		**valid;

	valid = NULL;
	if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
		return (NULL);
	set_room(room);
	valid = check_line(data, 3, ' ');
	if (valid)
	{
		room->name = ft_strdup(valid[0]);
		room->y = ft_atoi(valid[1]);
		room->x = ft_atoi(valid[2]);
		room->type = data->type;
		data->type = ROOM;
		ft_memdel_arlen((void**)valid);
	}
	if (data->error)
	{
		lstdel_room(&room);
		return (NULL);
	}
	return (room);
}

void			valid_links(t_game *data, int n)
{
	char		**links;

	links = NULL;
	if (!data->room)
		create_adj_list(data, data->nroom);
	if (!data->error && (links = check_line(data, 2, '-')))
	{
		while (++n < data->nroom)
		{
			if ((n == data->nroom) && ft_strequ(links[0], links[1]) &&
					(data->error = 9))
			{
				ft_memdel_arlen((void**)links);
				return ;
			}
			if (ft_strequ(links[0], data->room[n].name))
				data->link_n1 = n;
			if (ft_strequ(links[1], data->room[n].name))
				data->link_n2 = n;
		}
		(data->link_n1 >= 0 && data->link_n2 >= 0) ?
		room_relink(data, data->link_n1, data->link_n2) : (data->error = 11);
		if (links)
			ft_memdel_arlen((void**)links);
	}
}

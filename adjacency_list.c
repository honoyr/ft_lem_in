/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:45:45 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/23 16:45:47 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void				create_adj_list(t_game *data, int n)
{
	t_room		*tmp;
	t_room		*list;
	int			i;

	i = -1;
	if ((valid_list_room(data)))
		data->error = 5;
	if (!data->error && !(data->room = (t_room*)malloc(sizeof(t_room) * n)))
		data->error = 3;
	else if (!data->error && data->room)
	{
		tmp = data->room;
		list = data->list;
		while (++i < data->nroom)
		{
			tmp[i] = *list;
			tmp[i].link = NULL;
			tmp[i].ways = NULL;
			if (list->type == START)
				data->start = i;
			if (list->type == END)
				data->end = i;
			list = list->next;
		}
	}
}

int					valid_list_room(t_game *data)
{
	t_room		*tmp;
	int			st;
	int			end;

	st = 0;
	end = 0;
	tmp = data->list;
	while (tmp)
	{
		if (tmp->type == START)
			st++;
		if (tmp->type == END)
			end++;
		tmp = tmp->next;
	}
	if (st == 1 && end == 1)
		return (0);
	data->error = 12;
	return (1);
}

static void			lstback_link(t_link **lst, t_link *add)
{
	t_link		*tmp;

	tmp = NULL;
	if (lst && add)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = add;
	}
}

void				room_relink(t_game *data, int n1, int n2)
{
	t_link		*link1;
	t_link		*link2;

	if (!(link1 = (t_link*)malloc(sizeof(t_link) * 1)))
		data->error = 3;
	if (!(link2 = (t_link*)malloc(sizeof(t_link) * 1)))
		data->error = 3;
	if (!data->error)
	{
		link1->next = NULL;
		link2->next = NULL;
		link1->num = n2;
		link2->num = n1;
		if (!(data->room[n1].link))
			data->room[n1].link = link1;
		else
			lstback_link(&(data->room[n1].link), link1);
		if (!(data->room[n2].link))
			data->room[n2].link = link2;
		else
			lstback_link(&(data->room[n2].link), link2);
		data->link_n1 = -1;
		data->link_n2 = -1;
	}
}

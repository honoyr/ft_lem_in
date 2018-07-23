/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:19:01 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/24 16:19:03 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

t_ways			*create_ways(t_game *data, t_way *list_way, int length)
{
	t_ways		*new;

	if (!(new = (t_ways*)malloc(sizeof(t_ways) * 1)))
	{
		data->error = 3;
		return (NULL);
	}
	new->next = NULL;
	new->length = length;
	new->list_way = list_way;
	return (new);
}

t_way			*list_way(t_game *data, int *length)
{
	t_way		*list_way;
	t_way		*check;
	t_way		*new;

	list_way = NULL;
	list_way = create_way(data, data->end);
	while (data->room[list_way->num].ways)
	{
		check = data->room[list_way->num].ways;
		while (check->next && data->visited[check->num] == VISITED)
			check = check->next;
		if (data->visited[check->num] == VISITED)
			break ;
		new = create_way(data, check->num);
		new->next = list_way;
		list_way = new;
		if (check->num != data->start)
			data->visited[check->num] = VISITED;
		*length += 1;
	}
	return (list_way);
}

void			multiple_path(t_game *data, t_ways *ways)
{
	t_way		*tmp;
	t_way		*way;
	int			length;

	length = 0;
	way = NULL;
	tmp = data->room[data->end].ways;
	while (tmp)
	{
		way = list_way(data, &length);
		if (way->num == data->start)
			lstback_ways(&ways, create_ways(data, way, length));
		else
			lstdel_list_way(&way);
		tmp = tmp->next;
		length = 0;
	}
	if (ways)
		move_objects(data, ways);
	else
		data->error = 13;
}

void			valid_paths(t_game *data, int n_ways)
{
	t_ways		*ways;
	t_way		*tmp;

	ways = NULL;
	tmp = NULL;
	if (data->room[data->end].ways)
	{
		n_ways = 0;
		tmp = data->room[data->end].ways;
		while (tmp)
		{
			n_ways++;
			tmp = tmp->next;
		}
		ft_memset(data->visited, NO_VISITED, data->nroom);
		data->way_v = ft_strnew(n_ways);
		ft_memset(data->way_v, NO_VISITED, n_ways);
		multiple_path(data, ways);
	}
	else
		data->error = 13;
}

void			find_path(t_game *data, t_link *queue, t_link *tmp)
{
	queue = create_queue(data, data->start);
	while (queue)
	{
		tmp = data->room[queue->num].link;
		while (tmp)
		{
			if (data->visited[tmp->num] == IN_QUEUE)
				lstback_way(&(data->room[tmp->num].ways),
							create_way(data, queue->num));
			else if ((data->visited[tmp->num]) == NO_VISITED)
			{
				lstback_way(&(data->room[tmp->num].ways),
							create_way(data, queue->num));
				lstback_link_queue(&queue, create_queue(data, tmp->num));
				data->visited[tmp->num] = IN_QUEUE;
			}
			tmp = tmp->next;
		}
		data->visited[queue->num] = VISITED;
		tmp = queue;
		queue = queue->next;
		lstdel_one_link(&tmp);
	}
	valid_paths(data, 0);
}

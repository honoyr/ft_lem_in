/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:17:07 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/04 16:17:09 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void			print_ants(t_game *data, t_ant *ants)
{
	int			i;
	int			first;

	i = -1;
	first = 0;
	while (++i < data->ants)
	{
		if (ants[i].way && data->finish[i] == NO_FINISHED)
		{
			if (first > 0)
			{
				write(1, " ", 1);
				first = 0;
			}
			ft_printf("L%i-%s", ants[i].id, data->room[ants[i].cur_pos].name);
			first++;
		}
		if (ants[i].cur_pos == data->end)
		{
			data->finish[i] = FINISHED;
			ants[i].way->busy = false;
		}
	}
	write(1, "\n", 1);
}

t_ant			*create_ant(t_game *data)
{
	int			i;
	t_ant		*ants;

	i = -1;
	ants = NULL;
	if (!(ants = (t_ant*)malloc(sizeof(t_ant) * data->ants)))
	{
		data->error = 3;
		return (NULL);
	}
	data->finish = ft_strnew((data->ants));
	ft_memset(data->finish, NO_FINISHED, (data->ants));
	while (++i < data->ants)
	{
		ants[i].id = i + 1;
		ants[i].cur_pos = data->start;
		ants[i].way = NULL;
	}
	return (ants);
}

void			move_ants(t_ant *ants)
{
	if (ants->way)
	{
		ants->way->busy = false;
		ants->way = ants->way->next;
		if (ants->way)
		{
			ants->way->busy = true;
			ants->cur_pos = ants->way->num;
		}
	}
}

void			choose_path(t_game *data, t_ways *ways, t_ant *ant, int id)
{
	t_ways		*tmp_ways;
	int			div;
	int			rem;

	tmp_ways = ways;
	while (tmp_ways)
	{
		div = tmp_ways->length / ways->length;
		rem = tmp_ways->length % ways->length;
		if (((div == 1 && rem == 0) || (data->ants - id) > div))
		{
			if (tmp_ways->list_way->next->busy == false)
			{
				ant->way = tmp_ways->list_way;
				ant->way = ant->way->next;
				ant->way->busy = true;
				ant->cur_pos = ant->way->num;
				break ;
			}
		}
		tmp_ways = tmp_ways->next;
	}
}

void			move_objects(t_game *data, t_ways *ways)
{
	t_ant		*ants;
	int			i;

	i = -1;
	ants = NULL;
	ft_lstprint(&data->info);
	ft_lstdel_str(&data->info, (void*)(&ft_memdel));
	write(1, "\n", 1);
	if (!(ants = create_ant(data)))
		return ;
	while (ft_strchr(data->finish, NO_FINISHED))
	{
		while (++i < data->ants)
		{
			if (ants[i].cur_pos == data->start)
				choose_path(data, ways, &ants[i], (i + 1));
			else if (ants[i].cur_pos != data->end)
				move_ants(&ants[i]);
		}
		i = -1;
		print_ants(data, ants);
	}
	free(ants);
	lstdel_ways(&ways);
	ft_strdel(&data->finish);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:37:03 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/15 19:37:05 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

int        set_room(t_room *room)
{
    if (room)
    {
        room->name = NULL;
        room->type = -1;
        room->y = -1;
        room->x = -1;
        room->next = NULL;
        room->link = NULL;
        room->ways = NULL;
        return (1);
    }
    else
        return (0);
}

void set_data(t_game *data)
{
    data->ant = 0;
    data->type = ANT;
    data->start = -1;
    data->end = -1;
    data->nroom = 0;
    data->visited = NULL;
    data->line = NULL;
    data->list = NULL;
    data->room = NULL;
    data->info = NULL;
    data->error = 0;
    data->link_n1 = -1;
    data->link_n2 = -1;
}

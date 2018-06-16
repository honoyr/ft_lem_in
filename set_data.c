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

void        set_room(t_room *room)
{
    room->name = NULL;
    room->type = -1;
    room->y = -1;
    room->x = -1;
    room->next = NULL;
}

void set_data(t_game *data)
{
    data->ant = 0;
    data->type = ANT;
    data->start = -1;
    data->end = -1;
    data->nroom = -1;
    data->visited = NULL;
    data->line = NULL;
//    data->list->next = NULL;
//    data->list->x = -1;
//    data->list->y = -1;
//    data->list->type = -1;
//    data->room->name = -1;
    data->error = 0;
}

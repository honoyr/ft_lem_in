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

void        lstdel_link(t_link **link)
{
    t_link  *tmp;


    if (link)
    {
        while (*link)
        {
            tmp = *link;
            free(&(void*)tmp);
            *link = (*link)->next;
        }
        link = NULL;
    }

}

void        lstdel_room(t_room *room)
{
    lstdel_link(room->link);
    ft_strdel(&room->name);
    free(&(void*)room);
    room = NULL;
}


void        del_game(t_game *data)
{
    t_room  *tmp;

    tmp = data->list;
    ft_strdel(&data->visited);
    while (tmp)
    {
        lstdel_room(tmp);
        tmp = data->list->next;
    }
    free((void*)data->room);

}
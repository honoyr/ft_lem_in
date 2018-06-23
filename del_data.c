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


    if (*link)
    {
        while (*link)
        {
            tmp = *link;
            free((void*)tmp);
            *link = (*link)->next;
        }
        link = NULL;
    }

}

void        lstdel_room(t_room *room)
{
    if (room->link)
        lstdel_link(&room->link);
    if (room->name)
        ft_strdel(&room->name);
    free((void*)room);
    room = NULL;
}


void        del_game(t_game *data)
{
    t_room  *tmp;
    t_room  *lst;

    tmp = NULL;
    if (data->list)
    {
        tmp = data->list;
        lst = data->list;
    }
    if (data->visited)
        ft_strdel(&data->visited);
    while (tmp)
    {
        lstdel_room(tmp);
        lst = lst->next;
        tmp = lst;
    }
    data->list = NULL;
    free((void*)data->room);
}
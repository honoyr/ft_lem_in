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

void        lstdel_way(t_way **way)
{
    if (*way)
    {
        free(*way);
        *way = NULL;
    }
}

void        lstdel_list_way(t_way **list_way)
{
    t_way *tmp;


    if (*list_way)
    {
//        ft_printf("HERE 7\n");
        while (*list_way)
        {
            tmp = *list_way;
//            ft_printf("HERE 8\n");
            free(tmp);
            *list_way = (*list_way)->next;
        }
    }
}

void        lstdel_ways(t_ways **ways)
{
    t_ways  *tmp_ways;

    if (*ways)
    {
        while (*ways)
        {
            if ((*ways)->list_way)
                lstdel_list_way(&(*ways)->list_way);
            tmp_ways = *ways;
            free(tmp_ways);
            *ways = (*ways)->next;
        }
    }
}

void        lstdel_one_link(t_link **link)
{
    if (*link)
    {
        free(*link);
        *link = NULL;
    }
}

void        lstdel_link(t_link **link)
{
    t_link  *tmp;

    if (*link)
    {
        while (*link)
        {
            tmp = *link;
            free(tmp);
            *link = (*link)->next;
        }
    }
}

void        lstdel_room(t_room **room)
{
    if ((*room)->link)
    {
        lstdel_link(&((*room)->link));
    }
    if ((*room)->name)
        ft_strdel(&((*room)->name));
    //delete ways
    free(*room);
    *room = NULL;
}


void        del_game(t_game *data)
{
    t_room  *tmp;
    int     i;

    tmp = NULL;
    i = 0;
    if (data->visited)
        ft_strdel(&data->visited);
    if (data->way_v)
        ft_strdel(&data->way_v);
//    ft_printf("HERE 1\n");
    while (data->list)
    {
        tmp = data->list;
        lstdel_room(&tmp);
        data->list = data->list->next;
    }
//    ft_printf("HERE 2\n");
    if (data->room) {
        while (i < data->nroom) {
            if (data->room[i].link)
                lstdel_link(&data->room[i].link);
//            ft_printf("HERE 5\n");
            if (data->room[i].ways)
            {
                //data->room[i].ways = NULL; // I have no idea
//                ft_printf("WAY %i", data->room[i].ways->num);
                lstdel_list_way(&data->room[i].ways);
            }
//            ft_printf("HERE 6\n");
            i++;
        }
    }
//    ft_printf("HERE 3\n");
    if (data->room)
    {
        free(data->room);
        data->room = NULL;
    }
//    ft_printf("HERE 4\n");
}
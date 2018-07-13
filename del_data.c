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
        while (*list_way)
        {
            tmp = *list_way;
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
//            ft_printf("I'm here 2\n");
            tmp = *link;
            free(tmp);
            *link = (*link)->next;
        }
    }
}

void        lstdel_room(t_room **room)
{
//    ft_printf("I'm here 5\n");

//    ft_printf("LINKS\n");
//    t_link *tmp;
//        tmp = (*room)->link;
//        ft_printf("room = %s\n", (*room)->name);
//        while (tmp){
//            ft_printf("%s ", tmp->num);
//            tmp = tmp->next;
//        }
//        ft_printf("\n");



    if ((*room)->link)
    {
//        ft_printf("I'm here 3\n");
        lstdel_link(&((*room)->link));
    }
    if ((*room)->name)
        ft_strdel(&((*room)->name));
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
    while (data->list)
    {
        tmp = data->list;
        lstdel_room(&tmp);
        data->list = data->list->next;
    }
    while (i < data->nroom)
    {
        if (data->room[i].link)
            lstdel_link(&data->room[i].link);
        if (data->room[i].ways)
            lstdel_list_way(&data->room[i].ways);
        i++;
    }
    if (data->room)
    {
        free((void*)data->room);
        data->room = NULL;
    }
}
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
    t_link  *tmp_link;
    int     i;

    tmp = NULL;
    tmp_link = NULL;
    i = 0;
    if (data->visited)
        ft_strdel(&data->visited);
    while (data->list)
    {
        tmp = data->list;
        lstdel_room(&tmp);
        data->list = data->list->next;
    }
    while (i < data->nroom)
    {
        tmp_link = data->room[i].link;
        lstdel_link(&tmp_link);
        i++;
    }
    if (data->room)
    {
//        ft_printf("I'm here 4\n");
        free((void*)data->room);
        data->room = NULL;
    }
}
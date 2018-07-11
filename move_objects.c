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

void        print_data(t_game *data)
{
//    int     n_room;
//    t_room  *room;
//    t_link  *link;
//
//    n_room = 0;
////    info = ft_lstnew((void*)ft_itoa(data->ant), count_nbr(data->ant));
//    ft_printf("%i\n", data->ant);
//    while (data->nroom > n_room)
//    {
//        room = &data->room[n_room];
//        ft_printf("%s ", room->name);
//        ft_printf("%i ", room->y);
//        ft_printf("%i\n", room->x);
//        n_room++;
//    }
//    n_room = 0;
//    ft_memset(data->visited, NO_VISITED, data->nroom);
//    while (data->nroom > n_room)
//    {
//        link = data->room[n_room].link;
//        while (link)
//        {
//            ft_printf("%s-", data->room[link->num].name);
//            data->visited[link->num] = VISITED;
//            link = link->next;
//            ft_printf("%s\n", data->room[link->num].name);
//            data->visited[link->num] = VISITED;
//            link = link->next;
//        }
//        n_room++;
//    }
    ft_lstprint(&data->info);
    ft_lstdel_str(&data->info, (&ft_memdel));
}

t_ant       *create_ant(t_game *data, t_ways *ch_way)
{
    t_ant   *new;

    new = NULL;
    if (!(new = (t_ant*)malloc(sizeof(t_ant) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->id = 0;
    new->cur_pos = 0;
    new->way = ch_way;
    new->next = NULL;
    return (new);
}

t_ways      *choose_path(t_game *data, t_ways *ways, int n_way, int ants)
{
    t_ways  *tmp_ways;

    tmp_ways = ways;
    while (n_way >= 0)
    {
        tmp_ways = tmp_ways->next;
        if (ants >= tmp_ways->length)
            if (tmp_ways->list_way->busy == false)
            {
                tmp_ways = tmp_ways->next;
                break ;
            }
        n_way--;
    }
        return (tmp_ways);
}

void        move_objects(t_game *data, t_ways *ways)
{
    int     n_way;
    int     i;

    i = -1;
    t_ways  *ch_ways;
    n_way = count_path(ways);
    print_data(data);
    data->finish = ft_strnew(data->ants);
    ft_memset(data->finish, NO_FINISHED, data->ants);
    while (ft_strchr(data->finish, NO_FINISHED))
    {
        while(++i <= data->ants)
        {
            ch_ways = choose_path(data, ways, n_way, i);

        }

    }
}
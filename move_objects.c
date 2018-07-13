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
    write(1, "\n", 1);
}

void        print_ant(t_game *data, t_ant *ant)
{

    if (ant->cur_pos != data->start && data->finish[ant->id - 1] == NO_FINISHED)
        ft_printf("L%i-%s ", ant->id, data->room[ant->cur_pos].name);
    if (ant->cur_pos == data->end)
        data->finish[(ant->id - 1)] = FINISHED;
}

void        print_ants(t_game *data, t_ant *ants)
{
    int     i;

    i = -1;
    while (++i < data->ants)
    {
        if (ants[i].way && data->finish[i] == NO_FINISHED)
            ft_printf("L%i-%s ", ants[i].id, data->room[ants[i].cur_pos].name);
        if (ants[i].cur_pos == data->end)
            data->finish[i] = FINISHED;
    }
    write(1, "\n", 1);
}

t_ant        *create_ant(t_game *data, t_ant *ants)
{
    int i;

    i = -1;
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

void        move_ants(t_game *data, t_ant *ants)
{
//    int     i;
//
//    i = -1;
//    while (++i < data->ants)
//    {
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
//    }
}

//void        move_ants(t_game *data, t_ant *ants)
//{
//    int     i;
//
//    i = -1;
//    while (++i < data->ants)
//    {
//        if (ants[i].way)
//        {
//            ants[i].way->busy = false;
//            ants[i].way = ants[i].way->next;
//            if (ants[i].way)
//            {
//                ants[i].way->busy = true;
//                ants[i].cur_pos = ants[i].way->num;
//            }
//        }
//    }
//}

void      choose_path(t_game *data, t_ways *ways, t_ant *ant, int id)
{
    t_ways  *tmp_ways;
    int     div;
    int     rem;

    tmp_ways = ways;
    while (tmp_ways)
    {
        div = tmp_ways->length / ways->length;
        rem = tmp_ways->length % ways->length;
        if (((div == 1 && rem == 0) || data->ants - id > div))
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


void        move_objects(t_game *data, t_ways *ways)
{
    t_ant   *ants;
    int     i;

    i = -1;
    print_data(data);
    if (!(ants = create_ant(data, ants)))
        return;
    while (ft_strchr(data->finish, NO_FINISHED))
    {
        while(++i < data->ants)
        {
            if (ants[i].cur_pos == data->start)
                choose_path(data, ways, &ants[i], (i + 1));
            else if (ants[i].cur_pos != data->end)
                move_ants(data, &ants[i]);
        }
        i = -1;
        print_ants(data, ants);
    }
    free(ants);
    lstdel_ways(&ways);
    ft_strdel(&data->finish);
}
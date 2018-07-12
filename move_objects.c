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

//void        lstback_ants(t_ant **lst, t_ant *add)
//{
//    t_ant *tmp;
//
//    if (lst && *lst == NULL)
//        *lst = add;
//    else if(lst && add)
//    {
//        tmp = *lst;
//        while (tmp->next)
//        {
//            tmp = tmp->next;
//        }
//        tmp->next = add;
//    }
//}
void        print_ant(t_game *data, t_ant *ant)
{
    if (ant->way && data->finish[ant->id] == NO_FINISHED)
        ft_printf("L%i-%s ", ant->id, data->room[ant->cur_pos].name);
    if (ant->way && ant->way->num == data->end)
        data->finish[ant->id] = FINISHED;

}

void        print_ants(t_game *data, t_ant *ants)
{
    int     i;

    i = -1;
    while (++i <= data->ants)
    {
        if (ants[i].way && data->finish[ants[i].id] == NO_FINISHED)
        {
            ft_printf("L%i-%s ", ants[i].id, data->room[ants[i].cur_pos].name);
        }
    }

}

//t_ant       *create_ant(t_game *data, t_ways *ch_way, int id)
//{
//    t_ant   *new;
//
//    new = NULL;
//    if (!(new = (t_ant*)malloc(sizeof(t_ant) * 1)))
//    {
//        data->error = 3;
//        return (NULL);
//    }
//    new->id = -1;
////    new->cur_pos = data->start;
//    new->way = NULL;
//    return (new);
//}

t_ant        *create_ant(t_game *data, t_ant *ants)
{
    int i;

    i = -1;
    if (!(ants = (t_ant*)malloc(sizeof(t_ant) * data->ants)))
    {
        data->error = 3;
        return (NULL);
    }
    data->finish = ft_strnew((data->ants + 1));
    ft_memset(data->finish, NO_FINISHED, (data->ants + 1));
    while (++i <= data->ants)
    {
        ants[i].id = 0;
        ants[i].cur_pos = data->start;
        ants[i].way = NULL;
    }
    return (ants);
}

//t_ways      *choose_path(t_game *data, t_ways *ways, t_ant *ant, int id)
//{
//    t_ways  *tmp_ways;
//fffff
//    set_ant(ant, id);
//    tmp_ways = ways;
//    while (tmp_ways->next)
//    {
//        if (!(data->ants >= tmp_ways->length))
//            if (tmp_ways->list_way->busy == false)
//            {
//                tmp_ways = tmp_ways->next;
//                break ;
//            }
//        tmp_ways = tmp_ways->next;
//    }
//        return (tmp_ways);
//}

void        move_ants(t_game *data, t_ant *ants)
{
    int     i;

    i = -1;
    while (++i <= data->ants)
    {
        if (ants[i].way != NULL)
        {
            ants[i].way->busy = false;
            ants[i].way = ants[i].way->next;
            if (ants[i].way)
            {
                ants[i].way->busy = true;
                ants[i].cur_pos = ants[i].way->num;
            }
        }
        print_ant(data, &ants[i]);
    }
//    print_ants(data, ants);
}

void      ant_manipulation(t_game *data, t_ways *tmp_ways, t_ant *ant, int id)
{
    ant->id = id;
    ant->way = tmp_ways->list_way;
    ant->way = ant->way->next;
    ant->way->busy = true;
    ant->cur_pos = ant->way->num;
    print_ant(data, ant);
    if (ant->way->num == data->end)
        data->finish[id] = FINISHED;
    write(1, "\n", 1);
}

void      choose_path(t_game *data, t_ways *ways, t_ant *ant, int id, t_ant *ants)
{
    t_ways  *tmp_ways;

    tmp_ways = ways;
    move_ants(data, ants);
    while (tmp_ways)
    {
        if (data->ants == id)
        {
            ant_manipulation(data, tmp_ways, ant, id);
            break ;
        }
        if ((tmp_ways->length / ways->length) <= (data->ants - id))
        {
            if (tmp_ways->list_way->next->busy == false)
            {
                ant_manipulation(data, tmp_ways, ant, id);
//                tmp_ways->list_way->busy = true;
                break ;
            }
            tmp_ways = tmp_ways->next;
        }
    }
}


void        move_objects(t_game *data, t_ways *ways)
{
    t_ant   *ants;
    int     n_way;
    int     i;

    i = 0;
    data->ants;
    n_way = count_path(ways);
    print_data(data);
    ants = create_ant(data, ants);
    while (ft_strchr(data->finish, NO_FINISHED))
    {
        while(++i <= data->ants)
        {
            if (ants[i].cur_pos == data->start)
                choose_path(data, ways, &ants[i], i, ants);
            else if (ants[i].cur_pos != data->end)
                move_ants(data, ants);
        }
        i = -1;
//        print_ants(data, ants);
//        write(1, "\n", 1);
    }
    free(ants);
    lstdel_ways(&ways);
//            lstback_ants(&line, create_ant(data, ch_ways, i));
}
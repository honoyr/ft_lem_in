/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:19:01 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/24 16:19:03 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void	lstback_link_queue(t_link **lst, t_link *add)
{
    t_link *tmp;

    tmp = NULL;
    if (lst && add)
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = add;
    }
}

void	lstback_way(t_way **lst, t_way *add)
{
    t_way *tmp;

    tmp = NULL;
    if (*lst == NULL)
        *lst = add;
    else if(lst && add)
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = add;
    }
}

void	lstback_ways(t_ways **lst, t_ways *add)
{
    t_ways *tmp;

    tmp = NULL;
    if (*lst == NULL)
        *lst = add;
    else if(lst && add)
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = add;
    }
}

t_link      *create_queue(t_game *data, int queue)
{
    t_link  *new;

    if (!(new = (t_link*)malloc(sizeof(t_link) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->next = NULL;
    new->num = queue;
    return (new);
}

t_way      *create_way(t_game *data, int way)
{
    t_way  *new;

    if (!(new = (t_way*)malloc(sizeof(t_way) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->next = NULL;
    new->num = way;
    return (new);
}

t_ways      *create_ways(t_game *data, t_way *list_way, int length)
{
    t_ways  *new;

    if (!(new = (t_ways*)malloc(sizeof(t_ways) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->next = NULL;
    new->length = length;
    new->list_way = list_way;
    return (new);
}

int         count_ways(t_way *way)
{
    t_way *tmp;
    int     i;

    i = 0;
    tmp = NULL;
    tmp = way;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

void        multiple_path(t_game *data, t_ways *ways, int i, int n_ways)
{
    t_way  *tmp;
    t_way  *new;
    t_way  *list_way;
    int     length;
    int     v;

    v = 0;
    length = 0;
    list_way = NULL;
    while (++i < n_ways)
    {
        tmp = data->room[data->end].ways;
        list_way = create_way(data, data->end);
        while (tmp)
        {
            while (tmp->next && data->way_v[v] == VISITED)
            {
                tmp = tmp->next;
                v++;
            }
            data->way_v[v] = VISITED;
            if (data->visited[tmp->num] == NO_VISITED)
            {
                new = create_way(data, tmp->num);
                new->next = list_way;
                list_way = new;
                tmp = data->room[list_way->num].ways;
                data->visited[list_way->num] = VISITED;
                length++;
            }
            else
                tmp = NULL;
        }
        if (list_way->num == data->start)
            lstback_ways(&ways, create_ways(data, list_way, length));
        else
        {
            lstdel_list_way(&list_way);
            ft_memset(data->visited, NO_VISITED, data->nroom);
        }
        length = 0;
    }
    i = -1;
    tmp = NULL;
    while (ways && ++i < n_ways)
    {
        tmp = ways->list_way;
        ft_printf("WAY%i = ", i);
        while(tmp)
        {
            ft_printf("%i -> ", tmp->num);
            tmp = tmp->next;
        }
        ways = ways->next;
    }
    ft_printf("\n");
//    move_object(data, ways);
//    lstdel_ways(&ways);
}

void        valid_paths(t_game *data, int n_ways)
{
    t_ways  *ways;

    ways = NULL;
    if (data->room[data->end].ways)
    {
        n_ways = count_ways(data->room[data->end].ways);
        ft_memset(data->visited, NO_VISITED, data->nroom);
        data->way_v = ft_strnew(n_ways);
        ft_memset(data->way_v, NO_VISITED, n_ways);
        multiple_path(data, ways, -1, n_ways);
    }
    else
        data->error = 13;
}

void        find_path(t_game * data)
{
    t_link     *queue;
    t_link     *tmp;

    queue = create_queue(data, data->start);
    t_room *room;
    room = &data->room[2];
    while (queue)
    {
        tmp = data->room[queue->num].link;
        while (tmp)
        {
            if (data->visited[tmp->num] == IN_QUEUE)
                lstback_way(&(data->room[tmp->num].ways), create_way(data, queue->num));
            else if ((data->visited[tmp->num]) == NO_VISITED)
            {
                lstback_way(&(data->room[tmp->num].ways), create_way(data, queue->num));
                lstback_link_queue(&queue, create_queue(data, tmp->num));
                data->visited[tmp->num] = IN_QUEUE;
            }
            tmp = tmp->next;
        }
        data->visited[queue->num] = VISITED;
        tmp = queue;
        queue = queue->next;
        lstdel_one_link(&tmp);
    }
//    t_way *way;
//    t_room *room;
//    room = &data->room[data->end];
//    way = data->room[data->end].ways;
    valid_paths(data, 0);
}

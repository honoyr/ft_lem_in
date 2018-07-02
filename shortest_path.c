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

void	lstback_way(t_ways **lst, t_ways *add)
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

t_ways      *create_ways(t_game *data, int way)
{
    t_ways  *new;

    if (!(new = (t_ways*)malloc(sizeof(t_ways) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->next = NULL;
    new->num = way;
    return (new);
}

int         count_ways(t_ways *way)
{
    t_ways *tmp;
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
    t_ways  *tmp;
    t_ways  *new;
    t_ways  *way;

    way = create_ways(data, data->end);
    while (i < n_ways)
    {
        tmp = data->room[data->end].ways;
        while (tmp)
        {
            while (data->visited[tmp->num] == VISITED)
                tmp = tmp->next;
            data->visited[tmp->num] = VISITED;
            new = create_ways(data, tmp->num);
            new->next = way;
            way = new;
            tmp = data->room[way->num].ways;
        }
        ways[i] = *way;
        i++;
    }
}

void        valid_paths(t_game *data, int n_ways)
{
    t_ways  *ways;

    if (data->room[data->end].ways)
    {
        n_ways = count_ways(data->room[data->end].ways);
        ways = (t_ways*)malloc(sizeof(t_ways) * n_ways);
        ft_memset(data->visited, NO_VISITED, data->nroom);
        multiple_path(data, ways, 0, n_ways);
    }
    else
        data->error = 13;
}

//void        valid_paths(t_game *data, int i, int n)
//{
//    t_ways  *way;
//    t_ways  *tmp;
//    t_ways  *new;
//    t_ways  *ways;
//
//    if (data->room[data->end].ways)
//    {
//        n = count_ways(data->room[data->end].ways);
//        ways = (t_ways*)malloc(sizeof(t_ways) * n);
//        new = (t_ways*)malloc(sizeof(t_ways) * 1);
//        new->next = NULL;
//        way = data->room[data->end].ways;
//        tmp = create_ways(data, data->end);
//        while (i < n) {
//
//            while (data->room[tmp->num].ways)
//            {
//                new->num = data->room[tmp->num].ways->num;
//                new->next = tmp;
//                tmp = new;
//            }
//            ways[i] = *tmp;
//            way = way->next;
//            lstdel_way(&tmp);
//            tmp = create_ways(data, way->num);
//            i++;
//        }
//    }
//    else
//        data->error = 13;
//}

void        find_path(t_game * data)
{
    t_link     *queue;
    t_link     *tmp;

    queue = create_queue(data, data->start);
    while (queue)
    {
        tmp = data->room[queue->num].link;
        while (tmp)
        {
            if (data->visited[tmp->num] == IN_QUEUE)
                lstback_way(&(data->room[tmp->num].ways), create_ways(data, queue->num));
            else if ((data->visited[tmp->num]) == NO_VISITED)
            {
                lstback_way(&(data->room[tmp->num].ways), create_ways(data, queue->num));
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
    valid_paths(data, 0);
}

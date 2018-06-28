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

int	lstlast_link_queue(t_link **lst)
{
    t_link *tmp;

    tmp = NULL;
    if (lst)
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
    }
    return (tmp->num);
}

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

t_link      *create_queue(t_game *data)
{
    t_link  *new;

    if (!(new = (t_link*)malloc(sizeof(t_link) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->next = NULL;
    new->num = -1;
    return (new);
}

t_ways      *create_ways(t_game *data)
{
    t_ways  *new;

    if (!(new = (t_link*)malloc(sizeof(t_link) * 1)))
    {
        data->error = 3;
        return (NULL);
    }
    new->next = NULL;
    new->name = -1;
    return (new);
}

//void        find_path(t_game * data)
//{
//    t_link     *queue;
//    t_link     *next;
//    t_link     *tmp;
//    int         flag;
//
//    flag = 0;
//    queue = NULL;
//    data->visited = ft_strnew(data->nroom);
//    ft_memset(data->visited, NO_VISITED, data->nroom);
//    tmp = data->room[data->start].link;
//    queue = create_queue(data);
//    queue->num = data->start;
//    while (queue)
//    {
//        while (tmp)
//        {
//            if ((data->visited[tmp->num]) == NO_VISITED)
//            {
//                queue->next = create_queue(data);
//                if (tmp)
//                    queue->next->num = tmp->num;
//                lstback_link_queue(&queue, next);
//            }
//            else {
//                lstdel_one_link(&next);
//            }
//            tmp = tmp->next;
//        }
//        data->visited[queue->num] = VISITED;
//        if (data->room[queue->num].type == END) {
//            flag = 1;
//        }
//        next = queue;
//        queue = queue->next;
//        tmp = data->room[queue->num].link;
//        lstdel_one_link(&next);
//    }
//}

void        find_path(t_game * data)
{
    t_link     *queue;
    t_link     *next;
    t_link     *tmp;
    t_ways     *ways;
    t_ways     *ways_tmp;
    int         flag;

    flag = 0;
    ways_tmp = NULL;
    ways = NULL;
    data->visited = ft_strnew(data->nroom);
    ft_memset(data->visited, NO_VISITED, data->nroom);
    tmp = data->room[data->start].link;
    next = create_queue(data);
    next->num = data->start;
    queue = next;
    while (queue)
    {
        while (tmp)
        {
            next = create_queue(data);
            if (tmp)
                next->num = tmp->num;
            if ((data->visited[tmp->num]) == NO_VISITED)
                lstback_link_queue(&queue, next);
            else
                lstdel_one_link(&next);
            tmp = tmp->next;

        }
        data->visited[queue->num] = VISITED;
        if (data->room[queue->num].type == END)
            flag = 1;
        next = queue;
        ways_tmp = create_ways(data);
        lstback_way(&ways, ways_tmp);
        ways_tmp->name = queue->num;
        queue = queue->next;
        if (queue)
            tmp = data->room[queue->num].link;
        lstdel_one_link(&next);
    }
    lstdel_ways(&ways);
    lstdel_link(&queue);
}
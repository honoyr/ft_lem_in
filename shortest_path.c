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

//int	lstlast_link_queue(t_link **lst)
//{
//    t_link *tmp;
//
//    tmp = NULL;
//    if (lst)
//    {
//        tmp = *lst;
//        while (tmp->next != NULL)
//        {
//            tmp = tmp->next;
//        }
//    }
//    return (tmp->num);
//}

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

//void        in_queue(t_link **queue, char *visited)
//{
//    t_link  *tmp;
//
//    if (queue)
//    {
//        tmp = *queue;
//        while (tmp)
//        {
//            if (visited[tmp->num] == NO_VISITED)
//            {
//                visited[tmp->num] = IN_QUEUE;
//
//            }
//            tmp = tmp->next;
//        }
//    }
//
//}

//void        add_ways(t_link *queue, t_game *data)
//{
////    in_queue(&queue, data->visited);
//    t_link  *tmp;
//    int     way;
//
//    if (queue)
//    {
//        tmp = queue;
//        while (tmp)
//        {
//            if (data->visited[tmp->num] == NO_VISITED)
//            {
//                lstback_way(&(data->room[tmp->num].ways), create_ways(data, way));
//                data->visited[tmp->num] = IN_QUEUE;
//            }
//            way = tmp->num;
//            tmp = tmp->next;
//        }
//    }
//}

void        find_path(t_game * data)
{
    t_link     *queue;
    t_link     *tmp;

    data->visited = ft_strnew(data->nroom);
    ft_memset(data->visited, NO_VISITED, data->nroom);
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
}
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

void        find_path(t_game * data)
{
    t_link     *queue;
    t_link     *next;
    t_link     *tmp;
    t_room     *tmp_room;
    int         i;

    i = 0;
    queue = NULL;
    tmp_room = NULL;
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
            lstback_link_queue(&queue, next);
            tmp = tmp->next;
        }
        tmp_room = &data->room[queue->num];
        if ((data->visited[queue->num]) == NO_VISITED)
        {
            data->visited[queue->num] = VISITED;
            tmp = data->room[queue->num].link;
        }
        next = queue;
        lstdel_link(next);
        queue = queue->next;
    }

}
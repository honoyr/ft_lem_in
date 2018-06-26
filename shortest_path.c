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
    return (new);
}

void        find_path(t_game * data)
{
    t_link     *queue;
    t_link     *next;
    t_link     *tmp;
    t_room     *tmp_room;
    int         i;
    int         n;

    i = 0;
    data->visited = ft_strnew(data->nroom);
    ft_memset(data->visited, '0', data->nroom);
    queue = NULL;
    tmp = data->room[data->start].link;
    while (1)
    {
        while (tmp)
        {
            next = create_queue(data);
            next->num = tmp->num;
            if (!queue)
                queue = next;
            else if (data->visited[queue->num] = '0')
            {
                lstback_link_queue(&queue, next);
                data->visited[queue->num] = '1';
            }
            tmp = tmp->next;
        }
        tmp_room = &data->room[queue->num];
        queue = queue->next;
        tmp = data->room[queue->num].link;
    }

}
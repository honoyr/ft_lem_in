/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lem-in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:55:07 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/07 11:55:10 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void	lstback(t_room **lst, t_room *add)
{
    t_room *tmp;

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

int         check_int(char *ptr)
{
    int     j;
    int     i;

    j = 0;
    i = -1;
    while (ptr[++i])
    {
        if (ft_isdigit(ptr[i]))
            j++;
        j--;
    }
    if (j != 0)
        return (1);
    if (ft_strlen(ptr) > 10)
        return (1);
    if (ft_atoi(ptr) > 2147483647)
        return (1);
    return(0);
}

void        valid_ant(t_game *data)
{
    char    *ptr;

    ptr = ft_strtrim(data->line);
    if (!check_int(ptr))
        data->ant = ft_atoi(ptr);
    else
        data->error = 1;
    ft_strdel(&ptr);
}

void        create_list(t_game *data)
{
//    t_room      *tmp;
//
//    tmp = NULL;
//    tmp = data->list;
//    data->list = (t_room*)malloc(sizeof(t_room) * 1);
    data->nroom++;
    if (!data->list)
        data->list = valid_data(data);
    else if (data->list)
        lstback(&data->list, (valid_data(data)));
}

void          create_adj_list(t_game *data)
{
    t_rarr      *tmp;
    t_room      *list;
    int         i;

    i = 0;

//    if (valid_list(data))
//        data->error = 5;
    if (!(data->room = (t_rarr*)malloc(sizeof(t_rarr) * data->nroom)))
        data->error = 3;
    else if (data->room)
    {
        tmp = data->room;
        list = data->list;
        while (i < data->nroom)
        {
            tmp[i].name = list;
            list = list->next;
            i++;
        }
    }
}

t_room        *valid_data(t_game *data)
{
    t_room  *room;
    t_room  *tmp;
    char    *ptr;
    int     i;

    i = 0;
    tmp = NULL;
    ptr = ft_strtrim(data->line);
    if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
        data->error = 3;
    set_room(room);
    if (!room->name)
    {
        while (ptr[i] && !ft_whitespaces(ptr[i]))
            i++;
        room->name = ft_strsub(ptr, 0, i);
        room->y = ft_atoi(ft_strchr(ptr, ' '));
        room->x = ft_atoi(ft_strrchr(ptr, ' '));
        room->type = data->type;
        data->type = ROOM;
    }
    else
        data->error = 2;
    ft_strdel(&ptr);
    return (room);
}

void        valid_links(t_game *data)
{
    if (!data->room)
        create_adj_list(data);

}

int        valid_list(t_game *data)
{
    char    *ptr;

    ptr = ft_strtrim(data->line);

}
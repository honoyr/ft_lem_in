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

void        valid_ant(t_game *data)
{
    char    *ptr;
    int     j;
    int     i;

    j = 0;
    i = -1;
    ptr = ft_strtrim(data->line);
    while (ptr[++i])
    {
        if (ft_isdigit(ptr[i]))
            j++;
        j--;
    }
    if (j == 0)
        data->ant = ft_atoi(ptr);
    else
    {
        ft_printf("error: invalid format numbers of ants\n");
        data->error = 1;
    }
    ft_strdel(&ptr);
}

void        valid_data(t_game *data)
{
    t_room  *room;
    char    *ptr;
    int     i;

    i = 0;
    ptr = ft_strtrim(data->line);
    if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
        data->error;
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
    {
        ft_printf("error: data is invalid\n");
        data->error = 1;
    }
    ft_strdel(&ptr);
    lstback(&data->list, room);
    data->list = data->list->next;
}

void        valid_link(t_game *data)
{
    char    *ptr;

    ptr = ft_strtrim(data->line);

}
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

void        valid_start(t_game *data)
{
    t_room  room;
    char    *ptr;
    int     i;

    i = -1;
    ptr = ft_strtrim(data->line);
    set_room(&room);
    if (!room.name)
    {
        while (ptr[++i])
        {
            if (!room.name && ft_whitespaces(ptr[i]))
                room.name = ft_strsub(ptr, 0, (i > 0 ? 1 :(i - 1)));
            if (room.name && room.y != -1 && ft_isdigit(ptr[i]))
                room.x = ft_atoi(ptr + i);
            if (room.name && room.y == -1 && ft_isdigit(ptr[i]))
                room.y = ft_atoi(ptr + i);
        }
        room.type = START;
    }
    else
    {
        ft_printf("error: too many starts\n");
        data->error = 1;
    }
    ft_strdel(&ptr);
}
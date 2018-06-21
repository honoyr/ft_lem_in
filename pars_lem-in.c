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

int     check_name(char *name, t_game *data)
{
    int     i;

    i = -1;
    while (name[++i])
    {
        if (name[i] == ' ' || name[i] == '-' || name[i] == 'L')
        {
            data->error = 6;
            return (0);
        }
    }
    return (1);
}

int     check_coord(char *coord, t_game *data)
{
    int     i;

    i = -1;
    while (coord[++i])
    {
        if (!ft_isdigit(coord[i]))
        {
            data->error = 7;
            return (0);
        }
    }
    return (check_int(coord) ? 1 : 0);
}

char        **check_line(t_game *data)
{
    int     i;
    char    **arr;

    i = -1;
//    arr = ft_strsplit(data->line, ' ');
    if ((arr = ft_strsplit(data->line, ' ')))
    {
        while (arr[++i])
        {
            if (check_name(arr[0], data))
                break ;
            if (i > 0 && check_coord(arr[i], data))
                break ;
        }
        if (!data->error && *arr)
            return (arr);
    }
    data->error = 2;
    ft_memdel_arlen(arr);
    return (arr);
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
    t_room      *tmp;
    t_room      *list;
    int         i;

    i = 0;

//    if (valid_list(data))
//        data->error = 5;
    if (!(data->room = (t_room*)malloc(sizeof(t_room) * data->nroom)))
        data->error = 3;
    else if (data->room)
    {
        tmp = data->room;
        list = data->list;
        while (i < data->nroom)
        {
            tmp[i] = *list;
            list = list->next;
            i++;
        }
    }
}

//int            ihate_you_eval(t_game *data, t_room *room)
//{
//    int     i;
//    int     space;
//    int     digit;
//
//    i = -1;
//    space = 0;
//    digit = 0;
//    while (data->line[++i])
//    {
//        if (ft_whitespaces(data->line[i]))
//            space++;
//        if (ft_isdigit(data->line[i]))
//            digit++;
//    }
//    data->digit = digit;
//    if (space > 2 && digit)
//    {
//        room->name = ft_strsub(data->line, 0, (space - 2));
//        room->y = ft_atoi(data->line);
//        room->x = ft_atoi(ft_strrchr(data->line, ' '));
//        room->type = data->type;
//        data->type = ROOM;
//        return (1);
//    }
//    else
//        return (0);
//}

//t_room        *valid_data(t_game *data)
//{
//    t_room  *room;
//    char    *ptr;
//    int     i;
//
//    i = 0;
//    ptr = ft_strtrim(data->line);
//    if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
//        data->error = 3;
//    set_room(room); // we can del because malloc set structure by 0;
//    if (!room->name && !data->error && !ihate_you_eval(data, room))
//    {
//        while (ptr[i] && !ft_whitespaces(ptr[i]))
//            i++;
//        room->name = ft_strsub(ptr, 0, i);
//        room->y = ft_atoi(ft_strchr(ptr, ' '));
//        room->x = ft_atoi(ft_strrchr(ptr, ' '));
//        room->type = data->type;
//        data->type = ROOM;
//    }
////    else if (!room->name || !room->x || !room->y)
//    else if (!room->name)
//        data->error = 2;
//    ft_strdel(&ptr);
//    return (room);
//}

//t_room        *valid_data(t_game *data)
//{
//    t_room  *room;
//    int     i;
//
//    i = 0;
//    if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
//        data->error = 3;
//    set_room(room); // we can del because malloc set structure by 0;
//    if (!room->name && !ihate_you_eval(data, room) && data->digit)
//    {
//        while (data->line[i] && !ft_whitespaces(data->line[i]))
//            i++;
//        room->name = ft_strsub(data->line, 0, i);
//        room->y = ft_atoi(ft_strchr(data->line, ' '));
//        room->x = ft_atoi(ft_strrchr(data->line, ' '));
//        room->type = data->type;
//        data->type = ROOM;
//    }
////    else if (!room->name || !room->x || !room->y)
//    if (!room->name || !data->digit)
//        data->error = 2;
////    ft_strdel(&ptr);
//    return (room);
//}

t_room        *valid_data(t_game *data)
{
    t_room  *room;
    char    **valid;

    *valid = NULL;
    if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
        return (NULL);
//    set_room(room); // we can del because malloc set structure by 0;
    valid = check_line(data);
    if (*valid)
    {
        room->name = ft_strdup(valid[0]);
        room->y = ft_atoi(valid[1]);
        room->x = ft_atoi(valid[2]);
        room->type = data->type;
        data->type = ROOM;
        ft_memdel_arlen(valid);
    }
    if (data->error)
    {
        ft_strdel(&room);
        return (NULL);
    }
    return (room);
}

void        valid_links(t_game *data)
{
    int     n;
    char    *links_a;
    char    *links_b;

    n = data->nroom;
    if (!data->room)
        create_adj_list(data);
    if (!data->error)
    {
        links_a = ft_strsub(data->line, 0, ((ft_strchr(data->line, '-') - data->line)));
        links_b = ft_strdup(ft_strrchr(data->line, '-') + 1);
        while (n > 0)
        {
            if(ft_strequ(data->line, data->room[n].name))
            {

            }
            n--;
        }
    }

}

int        valid_list(t_game *data)
{
    char    *ptr;

    ptr = ft_strtrim(data->line);

}
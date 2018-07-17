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

void	lstback_link(t_link **lst, t_link *add, t_game *data)
{
    t_link *tmp;

    tmp = NULL;
    if (lst && add)
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            if (tmp->num == add->num)
            {
                data->error = 10;
                lstdel_link(&add);
                return;
            }
            tmp = tmp->next;
        }
        if (tmp->num == add->num)
        {
            data->error = 10;
            lstdel_link(&add);
            return;
        }
        tmp->next = add;
    }
}

void	lstback(t_room **lst, t_room *add, t_game *data)
{
    t_room *tmp;

    tmp = NULL;
    if (lst && add)
    {
        tmp = *lst;
        while (tmp->next != NULL)
        {
            if ((ft_strequ(tmp->name, add->name)) || (tmp->x == add->x && tmp->y == add->y))
            {
                lstdel_room(&add);
                data->error = 8;
                return;
            }
            tmp = tmp->next;
        }
        if ((ft_strequ(tmp->name, add->name)) || (tmp->x == add->x && tmp->y == add->y))
        {
            lstdel_room(&add);
            data->error = 8;
            return;
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
            return (1);
        }
    }
    return (0);
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
    return ((check_int(coord) ? 1 : 0));
}

char        **check_line(t_game *data, int flag, int c)
{
    int     i;
    char    **arr;

    i = -1;
    arr = NULL; // DEL
    if ((arr = ft_strsplit(data->line, c)))
    {
        while (arr[++i])
        {
            if (i < 3 && check_name(arr[i], data))
                break ;
            if (flag == 3 && i > 0 && check_coord(arr[i], data))
                break ;
        }
        if (i == flag && !data->error && *arr)
            return (arr);
    }
    data->error = 2;
    if (arr)
        ft_memdel_arlen((void**)arr);
    arr = NULL;
//    ft_printf("HERE 1\n");
    return (arr);
}

void        valid_ant(t_game *data)
{
    char    *ptr;

    ptr = ft_strtrim(data->line);
    if (!check_int(ptr))
        data->ants = ft_atoi(ptr);
    else
        data->error = 1;
    if (ptr)
        ft_strdel(&ptr);
}

void        create_list(t_game *data)
{
    t_room  *tmp;

    tmp = valid_data(data);
    if (!tmp)
        return;
    if (!data->list)
        data->list = tmp;
    else if (data->list)
        lstback(&data->list, tmp, data);
    data->nroom++;
//    ft_printf("4I'm here\n data->nroom = %i\n", data->nroom);
}

void          create_adj_list(t_game *data)
{
    t_room      *tmp;
    t_room      *list;
    int         i;

    i = -1;
    if ((valid_list_room(data)))
        data->error = 5;
    if (!data->error && !(data->room = (t_room*)malloc(sizeof(t_room) * data->nroom)))
        data->error = 3;
    else if (!data->error && data->room)
    {
        tmp = data->room;
        list = data->list;
        while (++i < data->nroom)
        {
            tmp[i] = *list;
            tmp[i].link = NULL;
            tmp[i].ways = NULL;
            if (list->type == START)
                data->start = i;
            if (list->type == END)
                data->end = i;
            list = list->next;
        }
    }
}

t_room        *valid_data(t_game *data)
{
    t_room  *room;
    char    **valid;

    valid = NULL;
    if (!(room = (t_room*)malloc(sizeof(t_room) * 1)))
        return (NULL);
    set_room(room); // we can del because malloc set structure by 0;
    valid = check_line(data, 3, ' ');
    if (valid)
    {
        room->name = ft_strdup(valid[0]);
        room->y = ft_atoi(valid[1]);
        room->x = ft_atoi(valid[2]);
        room->type = data->type;
        data->type = ROOM;
        ft_memdel_arlen((void**)valid);
    }
    if (data->error)
    {
        lstdel_room(&room);
        return (NULL);
    }
    return (room);
}

void        room_relink(t_game *data, int n1, int n2)
{
    t_link  *link1;
    t_link  *link2;

//    ft_printf("I'm here\n");
    if (!(link1 = (t_link*)malloc(sizeof(t_link) * 1)))
        data->error = 3;
    if (!(link2 = (t_link*)malloc(sizeof(t_link) * 1)))
        data->error = 3;
    if (!data->error)
    {
        link1->next = NULL;
        link2->next = NULL;
        link1->num = n2;
        link2->num = n1;
        if (!(data->room[n1].link))
            data->room[n1].link = link1;
        else
            lstback_link(&(data->room[n1].link), link1, data);
        if (!(data->room[n2].link))
            data->room[n2].link = link2;
        else
            lstback_link(&(data->room[n2].link), link2, data);
        data->link_n1 = -1;
        data->link_n2 = -1;
    }
}

void        valid_links(t_game *data)
{
    int     n;
    char    **links;

    links = NULL;
    n = -1;
    if (!data->room)
        create_adj_list(data);
    if (!data->error && (links = check_line(data, 2, '-')))
    {
        while (++n < data->nroom)
        {
            if (n == data->nroom && ft_strequ(links[0], links[1]) && (data->error = 9))
            {
                ft_memdel_arlen((void**)links);
                return ;
            }
            if(ft_strequ(links[0], data->room[n].name))
                data->link_n1 = n;
            if(ft_strequ(links[1], data->room[n].name))
                data->link_n2 = n;
        }
        if (data->link_n1 >= 0 && data->link_n2 >= 0)
            room_relink(data, data->link_n1, data->link_n2);
        else
            data->error = 11;
        if (links)
            ft_memdel_arlen((void**)links);
    }
//    ft_printf("2 I'm here\n data->nroom = %i\n", data->nroom);
}

int        valid_list_room(t_game *data)
{
    t_room  *tmp;
    int     st;
    int     end;

    st = 0;
    end = 0;
    tmp = data->list;
    while (tmp)
    {
        if (tmp->type == START)
            st++;
        if (tmp->type == END)
            end++;
        tmp = tmp->next;
    }
    if (st == 1 && end == 1)
        return (0);
    data->error = 12;
    return (1);
}
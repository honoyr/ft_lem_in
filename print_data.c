
#include "ft_lem.h"

void	ft_lstprint_d(t_list **lst)
{
    t_list *tmp;

    tmp = NULL;
    if (lst)
    {
        tmp = *lst;
        while (tmp)
        {
            ft_putstr(tmp->content);
            ft_putchar('\n');
            tmp = tmp->next;
        }
    }
}

void        print_type(int type)
{
    if (type == 5)
        ft_printf("%s\n", "ROOM");
    if (type == 4)
        ft_printf("%s\n", "COMM");
    if (type == 3)
        ft_printf("%s\n", "LINK");
    if (type == 2)
        ft_printf("%s\n", "END");
    if (type == 1)
        ft_printf("%s\n", "START");
    if (type == 0)
        ft_printf("%s\n", "ANT");
}

void        print_link(t_link *link)
{
    ft_printf("| LINK ");
    while (link)
    {
        ft_printf("%i", link->num);
        link = link->next;
        ft_printf("->");
    }
    ft_printf("\n");
}

void        print_come_from(t_way *way_from)
{
    ft_printf("| COME FROM ");
    while (way_from)
    {
        ft_printf("%i ", way_from->num);
        way_from = way_from->next;
        ft_printf("?");
    }
    ft_printf("\n");
}

void        print_room(t_room *room, t_game *data)
{
    int     n_room;


    n_room = 0;
    while (data->nroom > n_room)
    {
        room = &data->room[n_room];
        ft_printf("ROOM[%i] %s %i %i | TYPE = ", n_room, room->name, room->y, room->x);
        print_type(room->type);
        if (room->link)
            print_link(room->link);
        else
            ft_printf("\n");
        if (room->ways)
            print_come_from(room->ways);
        else
            ft_printf("\n");
        n_room++;
    }
}

void        print_game(t_game *data)
{
    t_room *tmp = NULL;
    int     i = 0;

    if (data->info)
    {
        ft_printf("What I get\n");
        ft_lstprint_d(&data->info);
        ft_printf("\n");
    }
    ft_printf("What I PARS\n");
    if (data->line)
        ft_printf("LAST GETNEXTLINE = %s\n", data->line);
    if (data->type)
    {
        ft_printf("TYPE = ");
        print_type(data->type);
    }
    if (data->ants)
        ft_printf("ANT %10i\n", data->ants);
    ft_printf("LIST OF ROOM\n");
    if (data->list)
    {
        tmp = data->list;
        while (tmp)
        {
            ft_printf("ROOM[%i] %s %i %i | TYPE = ", i, tmp->name, tmp->y, tmp->x);
            print_type(tmp->type);
            if (tmp->link)
                print_link(tmp->link);
            if (tmp->ways)
                print_come_from(tmp->ways);
            i++;
            tmp = tmp->next;
        }
        ft_printf("NUMBER OF LIST ROOM and nroom %i = %i \n", i, data->nroom);
    }
    ft_printf("\n");
    ft_printf("ARR OF ROOM\n");
    if (data->room)
    {
        ft_printf("NUMBER OF LIST ROOM and nroom %i = %i \n", i, data->nroom);
        ft_printf("\n");
        tmp = data->room;
        print_room(tmp, data);
    }
    if (data->start)
        ft_printf("START = %s", data->room[data->start].name);
    if (data->end)
        ft_printf("END = %s", data->room[data->end].name);
    if (data->way_v)
        ft_printf("WAY = %s", data->way_v);
    if (data->visited)
        ft_printf("LINE = %s", data->visited);
    if (data->line)
        ft_printf("LINE = %s", data->line);
}

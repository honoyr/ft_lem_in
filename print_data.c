
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

void        print_ways(t_ways *ways, t_game *data)
{
    int     i;
    int     n_ways;
    t_way  *tmp;
    i = -1;
    tmp = NULL;
    n_ways = count_ways(data->room[data->end].ways);
    while (ways && ++i < n_ways)
    {
        tmp = ways->list_way;
        ft_printf("WAY[%i] = ", i);
        while(tmp)
        {
            ft_printf("%i -> ", tmp->num);
            tmp = tmp->next;
        }
        ft_printf("| LENGTH %i\n", ways->length);
        ways = ways->next;
    }
    ft_printf("\n");
}

void        print_ways_r(t_ways *ways, t_game *data, t_room *rooms)
{
    int     i;
    int     n_ways;
    t_way  *tmp;
    t_ways  *ways_tmp;

    i = 0;
    tmp = NULL;
    ways_tmp = ways;
    n_ways = count_ways(data->room[data->end].ways);
    while (ways_tmp)
    {
        tmp = ways_tmp->list_way;
        ft_printf("WAY[%i] = ", i);
        while(tmp)
        {
            ft_printf("%s -> ", rooms[tmp->num].name);
            tmp = tmp->next;
        }
        ft_printf("| LENGTH %i\n", ways->length);
        ways_tmp = ways_tmp->next;
        i++;
    }
    ft_printf("\n");
}

void        print_type(int type)
{
    if (type == 5)
        ft_printf("%5s", "ROOM");
    if (type == 4)
        ft_printf("%5s", "COMM");
    if (type == 3)
        ft_printf("%5s", "LINK");
    if (type == 2)
        ft_printf("%5s", "END");
    if (type == 1)
        ft_printf("%5s", "START");
    if (type == 0)
        ft_printf("%5s", "ANT");
}

void        print_link(t_link *link)
{
    t_link  *tmp;

    tmp = link;
    ft_printf("| LINK ");
    while (tmp)
    {
        ft_printf("%i", tmp->num);
        tmp = tmp->next;
        ft_printf("->");
    }
//    ft_printf("\n");
}

void        print_come_from(t_way *way_from)
{
    t_way   *tmp;

    tmp = way_from;
    ft_printf("| COME FROM ");
    while (tmp)
    {
        ft_printf("%i ", tmp->num);
        tmp = tmp->next;
        ft_printf("?");
    }
//    ft_printf("\n");
}

void        print_link_r(t_room *room, t_room *rooms)
{
    t_link  *tmp;

    tmp = room->link;
    ft_printf("| LINK ROOM ");
    while (tmp)
    {
        ft_printf("%s", rooms[tmp->num].name);
        tmp = tmp->next;
        ft_printf("->");
    }
//    ft_printf("\n");
}

void        print_come_from_r(t_room *room, t_room *rooms)
{
    t_way  *tmp;

    tmp = room->ways;
    ft_printf("%30s", "| COME FROM ROOM ");
    while (tmp)
    {
        ft_printf("%s ", rooms[tmp->num].name);
        tmp = tmp->next;
        ft_printf("?");
    }
    ft_printf("\n");
}

void        print_room(t_room *room, t_game *data)
{
    int     i;


    i = 0;
    while (data->nroom > i)
    {
//        room = &data->room[n_room];
        ft_printf("ROOM[%i] %s %i %i | TYPE = ", i, room[i].name, room->y, room->x);
        print_type(room[i].type);
        if (room[i].link)
        {
//            print_link(room[i].link);
            print_link_r(&room[i], data->room);
        }
        if (room[i].ways)
        {
//            print_come_from(room[i].ways);
            print_come_from_r(&room[i], data->room);
        }
        else
            ft_printf("\n");
//        ft_printf("n_room %i", data->nroom);
        i++;
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
        ft_printf("\n");
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
            {
                print_come_from(tmp->ways);
                ft_printf("\n");
            }
            else
                ft_printf("\n");
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
    ft_printf("\n");
    ft_printf("ARR OF WAYS\n");
    if (data->start)
        ft_printf("%10s%s\n","START = ", data->room[data->start].name);
    if (data->end)
        ft_printf("%10s%s\n","END = ", data->room[data->end].name);
    if (data->way_v)
        ft_printf("%10s%s\n", "WAY = ", data->way_v);
    if (data->visited)
        ft_printf("%10s%s\n","VISITED = ", data->visited);
    if (data->finish)
        ft_printf("%10s%s\n","FINISH = ", data->finish);
    if (data->line)
        ft_printf("%10s%s\n","LINE = ", data->line);
    if (data->ways)
    {
//        print_ways(ways, data);
        print_ways_r(data->ways, data, data->room);
    }
}

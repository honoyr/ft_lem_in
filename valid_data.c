

#include "ft_lem.h"

void        valid_start_end(t_game *data)
{
//    t_link      *link;
//    t_room      *room;
//
//    room = data->room;
//    print_game(data);
    if (data->room)
    {
        if (!(data->room[data->end].link))
        {
            data->error = 15;
            error(data);
        }
        if (!(data->room[data->start].link))
        {
            data->error = 16;
            error(data);
        }
    }

//    while (++i < data->nroom)
//    {
//        link = room[i].link;
//
//        while (link)
//        {
//
//            link = link->next;
//        }
//    }
}
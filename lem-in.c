/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:54:19 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/07 11:54:23 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

char                *g_error[24] =
{
        "#0 empty file",
        "#1 invalid format numbers of ants",
        "#2 data is invalid",
        "#3 memory didn't allocated",
        "#4 pars invalid",
        "#5 list of rooms invalid",
        "#6 invalid name of room",
        "#7 invalid coordinates",
        "#8 double data in list of rooms",
        "#9 the link is linked to himself",
        "#10 the same links already exist",
        "#11 current rooms didn't exist in link",
        "#12 too many \"start\" or \"end\" "
        "#13 the end is unreachable"
};

void        pars_condition(t_game *data, char *line)
{
    if (line && (data->line = line))
    {
        if (line[0] != '#' && line[0] != 'L')
        {
            if (data->type == ANT)
                valid_ant(data);
            else if (ft_strchr(line, ' ') && data->type != ANT)
                create_list(data);
            else if (ft_strchr(line, '-'))
                valid_links(data);
            else
                data->error = 4;  // ADD IT
        }
        else
        {
            if (ft_strstr(data->line, "##start"))
                data->type = START;
            else if (ft_strstr(data->line, "##end"))
                data->type = END;
            else
                data->type = COMM;
        }
    }
    else
        data->error = 2;
}

//void        lem_in(char **line)
//{
//    t_game  data;
//    int     i;
//
//    i = -1;
//    set_data(&data);
////    while (get_next_line(fd, &line) > 0)
//    while(line[++i])
//    {
//        pars_condition(&data, line[i]);
////        ft_printf("good bay");
//        if (data.type != COMM)
////        if (data.type != COMM && data.type != START && data.type != END)
//        {
//            char *tmp;
//            tmp = line[i];
//            ft_lstback(&data.info, ft_lstnew((void*)line[i], ft_strlen(line[i])));
//        }
//        ft_strdel(&line[i]);
//        if (data.error)
//        {
////            error_manage(data.error);
//            ft_printf("error: %s\n", g_error[data.error]);
//            del_game(&data);
//            break ;
//        }
//    }
//    data.visited = ft_strnew(data.nroom);
//    ft_memset(data.visited, NO_VISITED, data.nroom);
//    find_path(&data);
////    ft_printf("LINKS\n");
////    t_link *tmp;
////    t_way *ptr;
////    int j;
////    j = 0;
////    while (j < data.nroom){
////        tmp = data.room[j].link;
////        ptr = data.room[j].ways;
////        ft_printf("room = %s\n", data.room[j].name);
////        while (tmp)
////        {
////            ft_printf("LINK %s ", data.room[tmp->num].name);
////            tmp = tmp->next;
////        }
////        ft_printf("\n");
////        while (ptr)
////        {
////            ft_printf("WAYS %i \n", ptr->num);
////            ptr = ptr->next;
////        }
////        ft_printf("\n");
////        j++;
////    }
//    del_game(&data);
//}

int     main(int ac, char **av)
{
    if (ac > 1 || ac < 1)
    {
        ft_printf("error");
        return (0);
    }
    t_game data;
    int res;

    set_data(&data);
    while ((res = get_next_line(0, &av[1]) > 0)) {
        pars_condition(&data, av[1]);
        if (data.type != COMM)
            ft_lstback(&data.info, ft_lstnew((void *) av[1], ft_strlen(av[1])));
        ft_strdel(&av[1]);
        if (data.error) {
            ft_printf("error: %s\n", g_error[data.error]);
            del_game(&data);
            break;
        }
    }
    if (res == 0)
    {
        data.visited = ft_strnew(data.nroom);
        ft_memset(data.visited, NO_VISITED, data.nroom);
        find_path(&data);
        del_game(&data);
    }
    return (0);
}

//    ft_printf("LINKS\n");
//    t_link *tmp;
//    t_way *ptr;
//    int j;
//    j = 0;
//    while (j < data.nroom){
//        tmp = data.room[j].link;
//        ptr = data.room[j].ways;
//        ft_printf("room = %s\n", data.room[j].name);
//        while (tmp)
//        {
//            ft_printf("LINK %s ", data.room[tmp->num].name);
//            tmp = tmp->next;
//        }
//        ft_printf("\n");
//        while (ptr)
//        {
//            ft_printf("WAYS %i \n", ptr->num);
//            ptr = ptr->next;
//        }
//        ft_printf("\n");
//        j++;
//    }




//        if (!(line = (char**)malloc(sizeof(char*) * 20)))
//            return (0);
//        line[0] = ft_strdup("4");
//        line[1] = ft_strdup("##start");
//        line[2] = ft_strdup("0 7 8");
//        line[3] = ft_strdup("1 5 6");
//        line[4] = ft_strdup("2 9 0");
//        line[5] = ft_strdup("##end");
//        line[6] = ft_strdup("3 13 0");
//        line[7] = ft_strdup("4 12 2");
//        line[8] = ft_strdup("0-1");
//        line[9] = ft_strdup("1-2");
//        line[10] = ft_strdup("1-4");
//        line[11] = ft_strdup("2-3");
//        line[12] = ft_strdup("4-3");
//        line[13] = NULL;
//    line[0] = ft_strdup("    7483648 ");
//    line[1] = ft_strdup("##start");
//    line[2] = ft_strdup("0 7 8");
//    line[3] = ft_strdup("1 5 6");
//    line[4] = ft_strdup("##start");
//    line[5] = ft_strdup("##end");
//    line[6] = ft_strdup("3 13 0");
//    line[7] = ft_strdup("4 12 2");
//    line[8] = ft_strdup("0-3");
//    line[9] = ft_strdup("3-1");
//    line[10] = ft_strdup("0-1");
//    line[11] = ft_strdup("1-4");
//    line[12] = ft_strdup("3-4");
//    line[13] = NULL;
//    line[0] = ft_strdup("    7483648 ");
//    line[1] = ft_strdup("##start");
//    line[2] = ft_strdup("0 7 8");
//    line[3] = ft_strdup("1 5 6");
//    line[4] = ft_strdup("2 5 3");
//    line[5] = ft_strdup("##end");
//    line[6] = ft_strdup("3 13 0");
//    line[7] = ft_strdup("4 12 2");
//    line[8] = ft_strdup("0-2");
//    line[9] = ft_strdup("0-1");
//    line[10] = ft_strdup("1-4");
//    line[11] = ft_strdup("1-3");
//    line[12] = ft_strdup("3-4");
//    line[13] = NULL;
//
//    line[0] = ft_strdup("6");
//    line[1] = ft_strdup("##start");
//    line[2] = ft_strdup("0 7 8");
//    line[3] = ft_strdup("1 5 6");
//    line[4] = ft_strdup("2 5 3");
//    line[5] = ft_strdup("##end");
//    line[6] = ft_strdup("3 13 0");
//    line[7] = ft_strdup("4 12 2");
//    line[8] = ft_strdup("5 14 2");
//    line[9] = ft_strdup("6 15 2");
//    line[10] = ft_strdup("0-1");
//    line[11] = ft_strdup("1-2");
//    line[12] = ft_strdup("2-4");
//    line[13] = ft_strdup("2-5");
//    line[14] = ft_strdup("2-6");
//    line[15] = ft_strdup("3-6");
//    line[16] = ft_strdup("4-3");
//    line[17] = ft_strdup("5-3");
//    line[18] = ft_strdup("#coment 345 43");
//    line[19] = NULL;
// error L
//    line[0] = ft_strdup("    7483648 ");
//    line[1] = ft_strdup("##start");
//    line[2] = ft_strdup("Lпри@$ĵ   15   23   ");
//    line[3] = ft_strdup("1 5 0");
//    line[4] = ft_strdup("2 9 0");
//    line[5] = ft_strdup("##end");
//    line[6] = ft_strdup("3 13 0");
//    line[7] = ft_strdup("0-2");
//    line[8] = ft_strdup("2-3");
//    line[9] = ft_strdup("3-1");
//    line[10] = NULL;
    // error #
//    line[0] = ft_strdup("    7483648 ");
//    line[1] = ft_strdup("##start");
//    line[2] = ft_strdup("при@$ĵ   15   23   ");
//    line[3] = ft_strdup("1 5 0");
//    line[4] = ft_strdup("2 9 0");
//    line[5] = ft_strdup("##end");
//    line[6] = ft_strdup("9 5 3");
//    line[7] = ft_strdup("3 13 0");
//    line[8] = ft_strdup("1-2");
//    line[9] = ft_strdup("2-3");
//    line[10] = ft_strdup("3-1");
//    line[11] = NULL;
//    lem_in(av[1]);
//    while (1) sleep(120);
//    system("leaks lem-in");
//	return (0);
//}
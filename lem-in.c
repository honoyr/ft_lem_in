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

char                *g_error[12] =
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

void	lstprint(t_room **lst) // DELETE
{
    t_room *tmp;

    tmp = NULL;
    if (lst)
    {
        tmp = *lst;
        while (tmp != NULL)
        {
//            ft_putstr(tmp->name);
//            ft_putchar('\n');
//            ft_printf("ROOM = %s|LINKS %i\n", tmp->name, tmp->link->num);
            tmp = tmp->next;
        }
    }
}

//void        error_manage(int  error)
//{
//    if (error == 1)
//        ft_putstr("error: #1 invalid format numbers of ants\n");
//    else if (error == 2)
//        ft_putstr("error: #2 data is invalid\n");
//    else if (error == 3)
//        ft_putstr("error: #3 memory didn't allocated\n");
//    else if (error == 4)
//        ft_putstr("error: #4 pars invalid\n");
//    else if (error == 5)
//        ft_putstr("error: #5 list of rooms invalid\n");
//    else if (error == 6)
//        ft_putstr("error: #6 invalid name of room \n");
//    else if (error == 7)
//        ft_putstr("error: #7 invalid coordinates \n");
//    else if (error == 8)
//        ft_putstr("error: #8 double data in list of rooms \n");
//    else if (error == 9)
//        ft_putstr("error: #9 the link is linked to himself \n");
//    else if (error == 10)
//        ft_putstr("error: #10 the same links already exist\n");
//    else if (error == 11)
//        ft_putstr("error: #11 current rooms didn't exist in link\n");
//    else if (error == 12)
//        ft_putstr("error: #12 too many \"start\" or \"end\" \n");
//}

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

void        lem_in(char **line)
{
    t_game  data;
    int     i;

    i = -1;
    set_data(&data);
//    while (get_next_line(fd, &line) > 0)
    while(line[++i])
    {
        pars_condition(&data, line[i]);
//        ft_printf("good bay");
        ft_strdel(&line[i]);
        if (data.error)
        {
//            error_manage(data.error);
            ft_printf("error: %s\n", g_error[data.error]);
            del_game(&data);
            break ;
        }
    }
    data.visited = ft_strnew(data.nroom);
    ft_memset(data.visited, NO_VISITED, data.nroom);
    find_path(&data);
    ft_printf("LINKS\n");
    t_link *tmp;
    t_ways *ptr;
    int j;
    j = 0;
    while (j < data.nroom){
        tmp = data.room[j].link;
        ptr = data.room[j].ways;
        ft_printf("room = %s\n", data.room[j].name);
        while (tmp)
        {
            ft_printf("LINK %s ", data.room[tmp->num].name);
            tmp = tmp->next;
        }
        ft_printf("\n");
        while (ptr)
        {
            ft_printf("WAYS %i \n", ptr->num);
            ptr = ptr->next;
        }
        ft_printf("\n");
        j++;
    }
    del_game(&data);
}

int     main(int ac, char **av)
{
		char    **line;

		if (ac > 1)
		{
			ft_printf("error");
			return (0);
		}
        if (!(line = (char**)malloc(sizeof(char*) * 14)))
            return (0);
        line[0] = ft_strdup("    7483648 ");
        line[1] = ft_strdup("##start");
        line[2] = ft_strdup("0 7 8");
        line[3] = ft_strdup("1 5 6");
        line[4] = ft_strdup("2 9 0");
        line[5] = ft_strdup("##end");
        line[6] = ft_strdup("3 13 0");
        line[7] = ft_strdup("4 12 2");
        line[8] = ft_strdup("0-1");
        line[9] = ft_strdup("1-2");
        line[10] = ft_strdup("1-4");
        line[11] = ft_strdup("2-3");
        line[12] = ft_strdup("4-3");
        line[13] = NULL;
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
    lem_in(line);
//    while (1) sleep(120);
//    system("leaks a.out");
	return (0);
}
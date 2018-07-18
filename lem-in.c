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
        "#12 too many start or end",
        "#13 the end is unreachable",
        "#14 data have't links",
        "#15 unreachable end",
        "#16 start donn't have a links",
};

void        pars_condition(t_game *data, char *line)
{
    if (line && line[0] != 'L' && (data->line = line))
    {
        if (line[0] != '#')
        {
            if (!ft_strlen(line))
                data->error = 2;
            else if (data->type == ANT)
                valid_ant(data);
            else if (ft_strchr(line, ' ') && data->type != ANT)
                create_list(data);
            else if (ft_strchr(line, '-') && (data->type = LINK))
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
        }
    }
    else
        data->error = 2;
}

void        error(t_game *data)
{
    if (data->error)
        ft_printf("error: %s\n", g_error[data->error]);
//    print_game(data);
    del_game(data);
//    system("leaks lem-in");
    exit(1);
}

int     main(int ac, char **av)
{
    if (ac > 1 || ac < 1)
    {
        ft_printf("error\n");
        return (0);
    }
    t_game data;
    int res;

    set_data(&data);
    while ((res = get_next_line(0, &av[1]) > 0))
    {
        pars_condition(&data, av[1]);
//        if (data.type != COMM)
        ft_lstback(&data.info, ft_lstnew((void *) av[1], ft_strlen(av[1])));
        ft_strdel(&av[1]);
        if (data.error)
            error(&data);
    }
    if (data.type != LINK || res == -1 || res == 1)
    {
        if (data.type != LINK)
            data.error = 14;
        else
            data.error = 2;
        if (data.error)
            error(&data);
        return (0);
    }
    else if (res == 0)
    {
        valid_start_end(&data);
        data.visited = ft_strnew(data.nroom);
        ft_memset(data.visited, NO_VISITED, data.nroom);
        find_path(&data);
        error(&data);
    }
    return (0);
}

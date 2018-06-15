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

void set_data(t_game *data)
{
    data->ant = 0;
    data->type = ANT;
    data->start = -1;
    data->end = -1;
    data->nroom = -1;
    data->visited = NULL;
    data->line = NULL;
    data->list->name = -1;
    data->list->x = -1;
    data->list->y = -1;
    data->list->type = -1;
//    data->room->name = -1;
}

void        pars_condition(t_game *data, char *line)
{
    set_data(data);
    if (line)
    {
        data->line = line;
        if (!(ft_strchr(line, '#')))
        {
            if (data->type == ANT)
                valid_ant(data);
            if (data->type == START)
                valid_start(data);
//        if (data->type == END)
//            valid_end(data);
//        if (data->type == LINK)
//            valid_link(data);
        }
        else
        {
            if (ft_strstr(data->line, "start"))
                data->type = START;
            else if (ft_strstr(data->line, "end"))
                data->type = END;
            else if (ft_strstr(data->line, "#"))
                data->type = COMM;
        }
    }
}

void        lem_in(char **line)
{
    t_game  data;
    int     i;

    i = -1;
//    while (get_next_line(fd, &line) > 0)
    while(line[++i])
    {
        pars_condition(&data, line[i]);
//        ft_printf("good bay");
//        ft_strdel(&line[i]);
    }
}

int     main(int ac, char **av)
{
		char    **line;

		if (ac > 1)
		{
			ft_printf("error");
			return (0);
		}
        if (!(line = (char**)malloc(sizeof(char*) * 11)))
            return (0);
        line[0] = ft_strdup(" 3    ");
        line[1] = ft_strdup("##start");
        line[2] = ft_strdup("0 1 0");
        line[3] = ft_strdup("##end");
        line[4] = ft_strdup("1 5 0");
        line[5] = ft_strdup("2 9 0");
        line[6] = ft_strdup("3 13 0");
        line[7] = ft_strdup("0-2");
        line[8] = ft_strdup("2-3");
        line[9] = ft_strdup("3-1");
        line[10] = NULL;
    lem_in(line);
	return (0);
}
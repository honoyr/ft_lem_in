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

void        error_manage(int  error)
{
    if (error == 1)
        ft_putstr("error: invalid format numbers of ants\n");
    else if (error == 2)
        ft_putstr("error: data is invalid\n");
    else if (error == 3)
        ft_putstr("error: memory didn't allocated\n");
}

void        pars_condition(t_game *data, char *line)
{
    if (line)
    {
        data->line = line;
        if (!(ft_strchr(line, '#')))
        {
            if (data->type == ANT)
                valid_ant(data);
            if (ft_strchr(line, ' ') && data->type != ANT)
                create_list(data);
//                valid_data(data);

//            if (ft_strchr(line, '-'))

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
    set_data(&data);
//    while (get_next_line(fd, &line) > 0)
    while(line[++i])
    {
        pars_condition(&data, line[i]);
//        ft_printf("good bay");
//        ft_strdel(&line[i]);
        if (data.error)
        {
            ft_printf("error\n");
            break ;
        }
    }
    ft_lstprint(&data.list);
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
        line[2] = ft_strdup("sta   15   23   ");
        line[3] = ft_strdup("1 5 0");
        line[4] = ft_strdup("2 9 0");
        line[5] = ft_strdup("##end");
        line[6] = ft_strdup("3 13 0");
        line[7] = ft_strdup("0-2");
        line[8] = ft_strdup("2-3");
        line[9] = ft_strdup("3-1");
        line[10] = NULL;
    lem_in(line);
	return (0);
}
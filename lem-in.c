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

void	lstprint(t_room **lst) // DELETE
{
    t_room *tmp;

    tmp = NULL;
    if (lst)
    {
        tmp = *lst;
        while (tmp != NULL)
        {
            ft_putstr(tmp->name);
            ft_putchar('\n');
            tmp = tmp->next;
        }
    }
}

void        error_manage(int  error)
{
    if (error == 1)
        ft_putstr("error: #1 invalid format numbers of ants\n");
    else if (error == 2)
        ft_putstr("error: #2 data is invalid\n");
    else if (error == 3)
        ft_putstr("error: #3 memory didn't allocated\n");
    else if (error == 4)
        ft_putstr("error: #4 pars invalid\n");
    else if (error == 5)
        ft_putstr("error: #5 list of rooms invalid\n");
    else if (error == 6)
        ft_putstr("error: #6 invalid name of room \n");
    else if (error == 7)
        ft_putstr("error: #7 invalid coordinates \n");
    else if (error == 8)
        ft_putstr("error: #8 double data in list of rooms \n");
    else if (error == 9)
        ft_putstr("error: #9 the link is linked to himself \n");
    else if (error == 10)
        ft_putstr("error: #10 the same links is already exist\n");
}

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
//                create_adj_list(data);

//        if (data->type == LINK)
//            valid_link(data);
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
            error_manage(data.error);
            del_game(&data);
            break ;
        }
    }
//    lstprint(&data.list);
}

int     main(int ac, char **av)
{
		char    **line;

		if (ac > 1)
		{
			ft_printf("error");
			return (0);
		}
        if (!(line = (char**)malloc(sizeof(char*) * 12)))
            return (0);
        line[0] = ft_strdup("    7483648 ");
        line[1] = ft_strdup("##start");
        line[2] = ft_strdup("3 7 8");
        line[3] = ft_strdup("1 5 0");
        line[4] = ft_strdup("2 9 0");
        line[5] = ft_strdup("##end");
        line[6] = ft_strdup("3 13 0");
        line[7] = ft_strdup("3-2");
        line[8] = ft_strdup("2-1");
        line[9] = ft_strdup("3-1");
        line[10] = NULL;
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
//    system("leaks");
	return (0);
}
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
    data->c = -1;
    data->x = -1;
    data->y = -1;
    data->next = NULL;
}

void        pars_condition(t_game *data, char *line)
{
    set_data(data);
}

int     main(int ac, char **av)
{
		int     fd;
		char    *line;
		t_game  data;

		fd = 0;
		line = NULL;

		if (ac > 1)
		{
			ft_printf("error");
			return (0);
		}
		while (get_next_line(fd, &line) > 0)
		{
			pars_condition(&data, line);
			ft_printf("good bay");
			ft_strdel(&line);
		}
	return (0);
}
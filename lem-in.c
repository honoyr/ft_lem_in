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

void set_data(t_room *ad_list)
{
    ad_list->c = -1;
    ad_list->x = -1;
    ad_list->y = -1;
    ad_list->next = NULL;
}

void        pars_condition(t_room **ad_list, char *line)
{

}

int     main(int ac, char **av)
{
		int     fd;
		char    *line;
		t_room   **ad_list;

		fd = 0;
		line = NULL;
		set_data(*ad_list);
		if (ac > 1)
		{
			ft_printf("error");
			return (0);
		}
		while (get_next_line(fd, &line) > 0)
		{
			pars_condition(ad_list, line);
			ft_printf("good bay");
			ft_strdel(&line);
		}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 20:24:53 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/23 20:24:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void			lstdel_list_way(t_way **list_way)
{
	t_way		*tmp;

	if (*list_way)
	{
		while (*list_way)
		{
			tmp = *list_way;
			free(tmp);
			*list_way = (*list_way)->next;
		}
	}
}

void			lstdel_ways(t_ways **ways)
{
	t_ways		*tmp_ways;

	if (*ways)
	{
		while (*ways)
		{
			if ((*ways)->list_way)
				lstdel_list_way(&(*ways)->list_way);
			tmp_ways = *ways;
			free(tmp_ways);
			*ways = (*ways)->next;
		}
	}
}

void			lstdel_one_link(t_link **link)
{
	if (*link)
	{
		free(*link);
		*link = NULL;
	}
}

void			lstdel_link(t_link **link)
{
	t_link		*tmp;

	if (*link)
	{
		while (*link)
		{
			tmp = *link;
			free(tmp);
			*link = (*link)->next;
		}
	}
}

void			lstdel_room(t_room **room)
{
	if ((*room)->link)
		lstdel_link(&((*room)->link));
	if ((*room)->name)
		ft_strdel(&((*room)->name));
	free(*room);
	*room = NULL;
}

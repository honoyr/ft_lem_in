/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:19:01 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/24 16:19:03 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"



void        find_path(t_game * data)
{
    t_list     *queue;
    int         *i;

    i = (int*)malloc(sizeof(int) * 1);
    *i = 3;
    queue = ft_lstnew(i, 1);
    data->visited = ft_strnew(data->nroom);
    ft_lstadd(queue, ft_lstnew(i, 1));

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_lem-in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:55:07 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/07 11:55:10 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void        valid_ant(t_game *data)
{
    char    *ptr;
    int     j;
    int     i;

    j = 0;
    i = -1;
    ptr = ft_strtrim(data->line);
    while (ptr[++i])
    {
        if (ft_isdigit(ptr[i]))
            j++;
        j--;
    }
    if (j == 0)
        data->ant = ft_atoi(ptr);
    else
        ft_printf("error: not valid format numbers of ants\n");
    ft_strdel(&ptr);
}

void        valid_start(t_game *data)
{
    char    *ptr;
    int     i;
    
    ptr = ft_strtrim(data->line);
    while (ptr[i])
    ft_strdel(&ptr);
}
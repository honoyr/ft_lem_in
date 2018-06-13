/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:10:38 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/07 12:10:41 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_H
# define FT_LEM_H

#include "./libft/libft.h"
# define START 1
# define END 2
# define ANT 0

typedef struct      s_info
{
    void            *data;
    struct s_info   *next;
}                   t_info;

typedef struct      s_link
{
    struct s_link   *next;
    int             num;
}                   t_link;

typedef struct      s_room
{
    char            name;
    int             x;
    int             y;
    int             type;
    struct s_room  *next;
}                   t_room;

typedef struct      s_rarr
{
    char    name;
    t_link  *link;
}                   t_rarr;

typedef struct      s_game
{
    unsigned int    ant;
    int             type;
    int             start;
    int             end;
    int             nroom;
    t_room          *list_rooms;
    t_rarr          *room;
    t_info          *info;

};                  t_game;

#endif

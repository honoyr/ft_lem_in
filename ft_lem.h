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
#include <stdbool.h>
# define ANT 0
# define START 1
# define END 2
# define LINK 3
# define COMM 4
# define ROOM 5
# define VISITED 49
# define NO_VISITED 48
# define IN_QUEUE 81
# define FINISHED 70
# define NO_FINISHED 78

extern char                *g_error[24];

typedef struct      s_way
{
    int             num;
    bool            busy;
    struct s_way   *next;
}                   t_way;

typedef struct      s_ways
{
    int             length;
    t_way           *list_way;
    struct s_ways   *next;
}                   t_ways;

typedef struct      s_link
{
    int             num;
    struct s_link   *next;
}                   t_link;

typedef struct      s_room
{
    char            *name;
    int             x;
    int             y;
    int             type;
    t_link          *link;
    t_way          *ways;
    struct s_room  *next;
}                   t_room;

typedef struct      s_ant
{
    int             id;
    int             cur_pos;
    t_way           *way;
}                   t_ant;

typedef struct      s_game
{
    int    ants;
    int             type;
    int             start;
    int             end;
    int             nroom;
    char            *visited;
    char            *finish;
    char            *way_v;
    char            *line;
    t_room          *list;
    t_room          *room;
    t_list          *info;
    int             error;
    int             link_n1;
    int             link_n2;
}                  t_game;

void        valid_ant(t_game *data);
t_room        *valid_data(t_game *data);
void        valid_links(t_game *data);
int        valid_list_room(t_game *data);

void        create_list(t_game *data);
void          create_adj_list(t_game *data);

int        set_room(t_room *room);
void        set_data(t_game *data);

int         count_ways(t_way *way);
int         count_path(t_ways *way);

void        lstdel_way(t_way **way);
void        lstdel_list_way(t_way **ways);
void        lstdel_ways(t_ways **ways);
void        lstdel_room(t_room **room);
void        lstdel_link(t_link **link);
void        lstdel_one_link(t_link **link);
void        del_game(t_game *data);

void        room_relink(t_game *data, int n1, int n2);

void        find_path(t_game * data);
void        move_objects(t_game *data, t_ways *ways);

void        print_game(t_game *data);

#endif

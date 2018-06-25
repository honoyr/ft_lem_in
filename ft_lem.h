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
# define ANT 0
# define START 1
# define END 2
# define LINK 3
# define COMM 4
# define ROOM 5

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
    char            *name;
    int             x;
    int             y;
    int             type;
    t_link          *link;
    struct s_room  *next;
}                   t_room;

//typedef struct      s_rarr
//{
//    char    *name;
//    t_link  *link;
//}                   t_rarr;

typedef struct      s_game
{
    unsigned int    ant;
    int             type;
    int             start;
    int             end;
    int             nroom;
    char            *visited;
    char            *line;
    t_room          *list;
    t_room          *room;
    t_info          *info;
    int             error;
//    int             digit; //del
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

void        lstdel_room(t_room **room);
void        lstdel_link(t_link **link);
void        del_game(t_game *data);

void        room_relink(t_game *data, int n1, int n2);

void        find_path(t_game * data);

#endif

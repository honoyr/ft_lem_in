/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:57:21 by dgonor            #+#    #+#             */
/*   Updated: 2018/07/23 19:57:23 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem.h"

void			lstback_link_queue(t_link **lst, t_link *add)
{
	t_link			*tmp;

	tmp = NULL;
	if (lst && add)
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
	}
}

void			lstback_way(t_way **lst, t_way *add)
{
	t_way			*tmp;

	tmp = NULL;
	if (*lst == NULL)
		*lst = add;
	else if (lst && add)
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
	}
}

void			lstback_ways(t_ways **lst, t_ways *add)
{
	t_ways			*tmp;

	tmp = NULL;
	if (*lst == NULL)
		*lst = add;
	else if (lst && add)
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = add;
	}
}

t_link			*create_queue(t_game *data, int queue)
{
	t_link			*new;

	if (!(new = (t_link*)malloc(sizeof(t_link) * 1)))
	{
		data->error = 3;
		return (NULL);
	}
	new->next = NULL;
	new->num = queue;
	return (new);
}

t_way			*create_way(t_game *data, int way)
{
	t_way		*new;

	if (!(new = (t_way*)malloc(sizeof(t_way) * 1)))
	{
		data->error = 3;
		return (NULL);
	}
	new->busy = false;
	new->next = NULL;
	new->num = way;
	return (new);
}

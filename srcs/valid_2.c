/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:48:41 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/23 13:48:43 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_t_room(t_lem *ers)
{
	t_room	*r1;
	int		i;

	r1 = ers->room;
	if (r1->room == NULL || ers->tmp != NULL)
	{
		if (r1->room == NULL && ft_t_room_b(ers, 1, r1))
			return (1);
		while (1)
		{
			i = -1;
			while (++i >= 0 && r1->room[i] == ers->tmp[i])
			{
				if (r1->room[i + 1] == '\0' && ers->tmp[i + 1] == '\0')
					return (0);
			}
			if (r1->next == NULL)
				break ;
			r1 = r1->next;
		}
		ft_t_room_b(ers, 2, r1);
		return (1);
	}
	return (0);
}

int		ft_t_room_b(t_lem *ers, int j, t_room *r1)
{
	if (j == 1)
	{
		if (ers->t == 1 && ers->start && ft_strcmp(ers->tmp, ers->start) == 0)
			ers->startz = r1;
		if (ers->t == 1 && ers->end && ft_strcmp(ers->tmp, ers->end) == 0)
			ers->endz = r1;
		r1->room = ft_strdup(ers->tmp);
		r1->next = NULL;
	}
	if (j == 2 && (r1->next = (t_room *)ft_memalloc(sizeof(t_room))))
	{
		r1 = r1->next;
		r1->room = ft_strdup(ers->tmp);
		if (ers->t == 1 && ers->start && ft_strcmp(ers->tmp, ers->start) == 0)
			ers->startz = r1;
		if (ers->t == 1 && ers->end && ft_strcmp(ers->tmp, ers->end) == 0)
			ers->endz = r1;
		r1->next = NULL;
	}
	return (1);
}

int		ft_t_coord(t_lem *ers)
{
	t_coord	*c1;
	int		i;

	c1 = ers->coord;
	if (c1->x == -1 || ers->tmp1 != NULL)
	{
		if (c1->x == -1 && ft_t_coord_b(1, ers, 1, c1))
			return (1);
		while (1)
		{
			if (c1->x == ft_atoi(ers->tmp1) && (i = 0) == 0)
			{
				while (ers->tmp1[i] && ft_isdigit(ers->tmp1[i]))
					i++;
				if (c1->y == ft_atoi(&ers->tmp1[i + 1]))
					return (0);
			}
			if (c1->next == NULL)
				break ;
			c1 = c1->next;
		}
		ft_t_coord_b(1, ers, 2, c1);
		return (1);
	}
	return (0);
}

int		ft_t_coord_b(int i, t_lem *ers, int j, t_coord *c1)
{
	if (j == 1)
	{
		c1->x = ft_atoi(ers->tmp1);
		i = 0;
		while (ers->tmp1[i] && ft_isdigit(ers->tmp1[i]))
			i++;
		c1->y = ft_atoi(&ers->tmp1[i + 1]);
		c1->next = NULL;
	}
	if (j == 2)
	{
		c1->next = (t_coord *)ft_memalloc(sizeof(t_coord));
		c1 = c1->next;
		c1->x = ft_atoi(ers->tmp1);
		i = 0;
		while (ers->tmp1[i] && ft_isdigit(ers->tmp1[i]))
			i++;
		c1->y = ft_atoi(&ers->tmp1[i + 1]);
		c1->next = NULL;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_1_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:58:39 by bkuksa            #+#    #+#             */
/*   Updated: 2019/06/17 19:58:42 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_alg_room(t_lem *ers, t_room *r, t_atm *atm, t_room *r2)
{
	r2 = r;
	while (r2)
	{
		atm = r2->atm;
		while (atm != NULL)
		{
			if (atm->fin->stop == 0 && atm->fin->len == 0
			&& atm->fin != ers->endz)
				ft_alg_new_room(ers, atm->fin, r2);
			else if (atm->fin == ers->endz)
				ft_route(ers, atm->fin, r2);
			if (ers->k == 1)
			{
				ft_clean_graf(ers);
				ers->turn = ers->startz;
				ers->turn2 = NULL;
				ers->turn3 = NULL;
				return ;
			}
			atm = atm->next;
		}
		if (r2->turn == NULL)
			break ;
		r2 = r2->turn;
	}
}

void	ft_clean_graf(t_lem *ers)
{
	t_room	*r1;

	r1 = ers->room;
	r1->turn = NULL;
	r1->len = 0;
	r1->prev = 0;
	ers->v++;
	while (1)
	{
		if (r1->next == NULL)
			break ;
		r1 = r1->next;
		r1->turn = NULL;
		r1->len = 0;
		r1->prev = 0;
	}
}

void	ft_alg_new_room(t_lem *ers, t_room *r, t_room *p)
{
	t_room	*r2;

	if (ft_search_in_turn(ers, r, 0) == 0)
		return ;
	r2 = ers->turn2;
	if (r2 == NULL && ++ers->v)
	{
		ers->turn2 = r;
		r->prev = p;
		r->len = p->len + 1;
		return ;
	}
	while (r2)
	{
		if (r2->turn == NULL && ++ers->v)
		{
			r2->turn = r;
			r->prev = p;
			r->len = p->len + 1;
			return ;
		}
		if (r2->turn != NULL)
			r2 = r2->turn;
	}
}

int		ft_search_in_turn(t_lem *ers, t_room *r, int i)
{
	t_room	*t;
	int		k;

	k = 1;
	t = NULL;
	if (i == 0 && ers->turn)
		t = ers->turn;
	if (i == 1 && ers->turn2)
		t = ers->turn2;
	if (i == 2 && ers->turn3)
		t = ers->turn3;
	while (t)
	{
		if (r == t)
			return (0);
		if (t->turn == NULL)
			break ;
		t = t->turn;
	}
	if (i + 1 < 3)
		k = ft_search_in_turn(ers, r, i + 1);
	return (k);
}

void	ft_route(t_lem *ers, t_room *end, t_room *prev)
{
	if (prev == ers->startz)
		ers->f++;
	if (ft_if_new_route(ers, end, prev) == 0)
		return ;
	if (ers->f == 0)
		ft_route3(ers, end, prev);
}

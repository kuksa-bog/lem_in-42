/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:42:16 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/27 12:42:19 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_get_alg(t_lem *ers)
{
	ft_initial_room(ers, NULL, NULL);
	ers->now = ers->startz;
	ers->now1 = ers->startz;
	ers->turn = ers->startz;
	ers->now->len = 0;
	ers->v = 1;
	ers->k = 0;
	ers->f = 0;
	while (ers->v != 0 && (ers->v = 0) == 0)
	{
		ers->k = 0;
		ft_alg_room(ers, ers->turn, NULL, NULL);
		if (ers->turn != NULL && ers->turn2 != NULL)
		{
			ers->turn3 = ers->turn;
			ers->turn = ers->turn2;
			ers->turn2 = NULL;
		}
	}
	if (ers->f == 1 || ers->route != NULL)
	{
		ft_write(ers);
		ft_run_ant(ers);
	}
}

void	ft_initial_room(t_lem *ers, t_str *link, t_str *link2)
{
	char	*s1;
	char	*s2;
	t_room	*r1;
	t_room	*r2;

	link = ers->link;
	while (link && (s1 = ft_cut_1(link, 1)) != NULL)
	{
		s2 = ft_cut_1(link, 2);
		r1 = ft_search_room(ers, s1);
		r2 = ft_search_room(ers, s2);
		ft_new_atm(r1, r2, NULL);
		ft_strdel(&s1);
		ft_strdel(&s2);
		if (link->next == NULL)
		{
			ft_strdel(&link->str);
			free(link);
			break ;
		}
		link2 = link->next;
		ft_strdel(&link->str);
		free(link);
		link = link2;
	}
}

void	ft_new_atm(t_room *r1, t_room *r2, t_atm *atm)
{
	if (r1->atm != NULL && (atm = r1->atm))
	{
		while (atm->next)
			atm = atm->next;
		atm->next = (t_atm *)ft_memalloc(sizeof(t_atm));
		atm->next->fin = r2;
	}
	else
	{
		r1->atm = (t_atm *)ft_memalloc(sizeof(t_atm));
		r1->atm->fin = r2;
	}
	if (r2->atm != NULL && (atm = r2->atm))
	{
		while (atm->next)
			atm = atm->next;
		atm->next = (t_atm *)ft_memalloc(sizeof(t_atm));
		atm->next->fin = r1;
	}
	else
	{
		r2->atm = (t_atm *)ft_memalloc(sizeof(t_atm));
		r2->atm->fin = r1;
	}
}

t_room	*ft_search_room(t_lem *ers, char *s)
{
	t_room	*r;

	r = ers->room;
	while (1)
	{
		if (ft_strcmp(s, r->room) == 0)
			return (r);
		if (r->next == NULL)
			break ;
		r = r->next;
	}
	return (NULL);
}

char	*ft_cut_1(t_str *link, int i)
{
	char	*s;
	int		j;
	int		g;

	s = NULL;
	j = 0;
	g = 0;
	while (link->str[j] != '-' && ++g)
		++j;
	if (i == 1)
		s = ft_strndup(link->str, g);
	if (i == 2)
		s = ft_strdup(&link->str[j + 1]);
	return (s);
}

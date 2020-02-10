/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_1_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:58:48 by bkuksa            #+#    #+#             */
/*   Updated: 2019/06/17 19:58:50 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_run_ant(t_lem *ers)
{
	t_route	*route;
	int		k;
	int		z;

	if (ers->f == 1)
	{
		ft_if_one(ers);
		return ;
	}
	route = ers->route;
	z = 0;
	k = (ers->x + ers->ant - ers->y) % (ers->y);
	k = (k > 0) ? ers->y - k : 0;
	while (route)
	{
		route->ants = ers->h - route->len + 1;
		route->ants = (k > 0) ? route->ants - 1 : route->ants;
		z = z + route->ants;
		route->ant = 1;
		if (k > 0)
			k--;
		route = route->next;
	}
	ft_run_ant2(ers);
}

void	ft_run_ant2(t_lem *ers)
{
	ers->v = 1;
	ers->count = 1;
	ers->ant3 = 1;
	while (ers->v != 0 && ers->k2 <= ers->ant)
	{
		ers->v = 0;
		ft_if_run(ers);
		if (ers->v != 0)
			ft_putstr("\n");
		ers->count++;
	}
}

void	ft_if_run(t_lem *ers)
{
	t_route	*r;

	r = ers->route;
	while (1)
	{
		ft_run(ers, r, NULL, NULL);
		if (r->next == NULL)
			break ;
		r = r->next;
	}
}

void	ft_run(t_lem *ers, t_route *r, t_atm *atm, t_atm *atm2)
{
	atm = r->atm;
	atm2 = atm;
	while (atm)
	{
		if (atm->fin != ers->endz && atm->count != ers->count)
		{
			if ((atm->count = ers->count) && atm->ant != 0)
			{
				ers->str = ft_itoa(atm->ant);
				ft_putchar('L');
				ft_putstr(ers->str);
				ft_putchar('-');
				ft_putstr(atm2->fin->room);
				ft_putchar(' ');
				if (++ers->v && atm2->fin != ers->endz)
					atm2->ant = atm->ant;
				atm->ant = 0;
				ft_strdel(&ers->str);
			}
		}
		atm = atm->next;
		if (atm2->next != atm)
			atm2 = atm2->next;
	}
	ft_run2(ers, r, atm2);
}

void	ft_run2(t_lem *ers, t_route *r, t_atm *atm2)
{
	char	*s;

	s = ft_itoa(ers->ant3);
	if (r->ant <= r->ants && r->count != ers->count && ++ers->v)
	{
		r->count = ers->count;
		ft_putchar('L');
		ft_putstr(s);
		ft_putchar('-');
		ft_putstr(atm2->fin->room);
		ft_putchar(' ');
		r->ant++;
		atm2->ant = ers->ant3;
		ers->ant3++;
	}
	ft_strdel(&s);
}

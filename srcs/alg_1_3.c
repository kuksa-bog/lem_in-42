/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_1_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:58:56 by bkuksa            #+#    #+#             */
/*   Updated: 2019/06/17 19:59:02 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_strjoin_fix(char *s1, char *s2, int n)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	if (n == 1 && s1)
	{
		ft_strdel(&s1);
		s1 = NULL;
	}
	if (n == 2 && s2)
	{
		ft_strdel(&s2);
		s2 = NULL;
	}
	if (n == 3 && s1 && s2)
	{
		ft_strdel(&s2);
		s2 = NULL;
		ft_strdel(&s1);
		s1 = NULL;
	}
	return (s3);
}

int		ft_strstr_lem(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i])
	{
		i++;
		if (s2[i] == '\0' && s1[i] == '-')
			return (0);
	}
	i = 0;
	while (s1[i] != '-')
		i++;
	j = 0;
	i++;
	while (s1[i] == s2[j])
	{
		i++;
		j++;
		if ((s1[i] == '-' || s1[i] == '\0') && s2[j] == '\0')
			return (0);
	}
	return (1);
}

void	ft_route3(t_lem *ers, t_room *end, t_room *prev)
{
	t_route	*r;

	r = ers->route;
	if (r == NULL && (ers->k = 1) == 1)
	{
		ers->y = 1;
		ers->route = (t_route *)ft_memalloc(sizeof(t_route));
		ers->route->len = ft_route2(ers, end, prev, ers->route);
		ers->x = ers->route->len;
		ers->h = (ers->x + ers->ant - ers->y) / ers->y;
		ers->h = ((ers->x + ers->ant - ers->y) % ers->y > 0)
										? ers->h + 1 : ers->h;
	}
	else if ((ers->k = 1) == 1)
	{
		while (r->next != NULL)
			r = r->next;
		ers->y++;
		r->next = (t_route *)ft_memalloc(sizeof(t_route));
		r->next->len = ft_route2(ers, end, prev, r->next);
		ers->x = ers->x + r->next->len;
		ers->h = (ers->x + ers->ant - ers->y) / ers->y;
		ers->h = ((ers->x + ers->ant - ers->y) % ers->y > 0)
				? ers->h + 1 : ers->h;
	}
}

int		ft_route2(t_lem *ers, t_room *end, t_room *prev, t_route *r)
{
	t_atm	*atm;
	int		i;

	r->atm = (t_atm *)ft_memalloc(sizeof(t_atm));
	r->atm->fin = end;
	i = 1;
	atm = r->atm;
	while (1)
	{
		if (prev == ers->startz)
			break ;
		atm->next = (t_atm *)ft_memalloc(sizeof(t_atm));
		atm->next->fin = prev;
		prev->stop = 1;
		i++;
		prev = prev->prev;
		atm = atm->next;
	}
	return (i);
}

int		ft_if_new_route(t_lem *ers, t_room *end, t_room *prev)
{
	int		i;
	int		k;
	t_atm	*atm;

	i = 1;
	if (ers->route == NULL || ers->h == 0)
		return (1);
	else
	{
		while (1)
		{
			i++;
			if (prev->prev == ers->startz)
				break ;
			prev = prev->prev;
		}
		k = (ers->x + i + ers->ant - ers->y - 1) / (ers->y + 1);
		k = ((ers->x + i + ers->ant - ers->y - 1)
				% (ers->y + 1) == 0) ? k : k + 1;
		if ((ers->h < k && k < i) || k < i)
			return (0);
	}
	return (1);
}

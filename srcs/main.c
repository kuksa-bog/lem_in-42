/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:48:52 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/15 12:48:55 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_lem	*ers;

	ers = ft_initialization();
	ers->fd = 0;
	ft_get_graf(ers);
	if (ers->error == 0)
	{
		ers->h = 0;
		ers->x = 0;
		ers->y = 0;
		ft_get_alg(ers);
	}
	else if (ers->error != 0)
		write(1, "ERROR\n", 6);
	return (0);
}

t_lem	*ft_initialization(void)
{
	t_lem	*ers;

	ers = (t_lem *)ft_memalloc(sizeof(t_lem));
	ers->room = (t_room *)ft_memalloc(sizeof(t_room));
	ers->room->next = NULL;
	ers->coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	ers->coord->x = -1;
	ers->coord->y = -1;
	ers->coord->next = NULL;
	ers->link = (t_str *)ft_memalloc(sizeof(t_str));
	ers->input = ft_memalloc(sizeof(t_str));
	ers->link->next = NULL;
	ers->start = NULL;
	ers->end = NULL;
	ers->tmp = NULL;
	ers->tmp1 = NULL;
	ers->ant = 0;
	ers->error = 0;
	ers->b = 0;
	ers->i = 0;
	ers->valid = 0;
	return (ers);
}

void	ft_get_graf(t_lem *ers)
{
	ers->input2 = ers->input;
	ers->input2->str = NULL;
	while (ers->error == 0 && get_next_line(ers->fd, &ers->input2->str) > 0)
	{
		if (ers->valid == 0 && ers->error == 0 && ers->ant == 0)
			ft_valid_ants(ers, ers->input2->str);
		else if (ers->error == 0 && ers->valid == 1
							&& ft_if_valid_next(ers, ers->input2->str) == 1)
			ft_get_room(ers, &ers->input2->str);
		else if (ers->error == 0 && ers->valid == 2)
			ers->error = (ft_get_link(ers, ers->input2->str) == 1) ? 0 : 1;
		if (ers->input2->str[0] == '#' && ers->input2->str[1] != '#')
			ers->error = 0;
		if (ers->error == 0)
		{
			ers->input2->next = ft_memalloc(sizeof(t_str));
			ers->input2 = ers->input2->next;
			ers->input2->next = NULL;
			ers->input2->str = NULL;
		}
	}
	if (ers->valid != 2)
		ers->error = 1;
}

int		ft_get_link(t_lem *ers, char *l)
{
	int		i;

	i = 0;
	if (l[0] == '#')
		return (1);
	while (l[i] && l[i] != '-')
	{
		if (l[i] == ' ')
			return (0);
		i++;
	}
	if ((ers->i = i + 1) && l[i] != '-')
		return (0);
	return (ft_get_link2(ers, l, i));
}

int		ft_get_link2(t_lem *ers, char *l, int i)
{
	char	*s;

	if ((s = ft_strndup(l, i)) != NULL && ft_valid_link(ers, s, 1, l) != 0)
	{
		i++;
		if (ft_valid_link(ers, s, i, l) == 0)
		{
			free(s);
			return (0);
		}
		if (ft_t_link(ers, l) == 1)
		{
			free(s);
			return (1);
		}
	}
	free(s);
	return (0);
}

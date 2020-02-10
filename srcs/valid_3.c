/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:19:46 by bkuksa            #+#    #+#             */
/*   Updated: 2019/07/31 17:19:48 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_get_room(t_lem *ers, char **l)
{
	int		k;

	ers->t = 0;
	k = ft_valid_room(ers, *l);
	if (k == 0 && (ers->error = 1))
		return (0);
	if ((ers->b == 1 || ers->b == 2) && (k == 1 || k == 2 || k == 0)
		&& (ers->error = 1))
		return (0);
	if (k == 2)
		return (0);
	if (ers->error == 0 && k == 1)
	{
		(ft_strncmp(*l, "##start", ft_strlen(*l)) == 0) ? ers->b = 1 : 0;
		(ft_strncmp(*l, "##end", ft_strlen(*l)) == 0) ? ers->b = 2 : 0;
		if (ers->b == 1 || ers->b == 2)
			return (0);
	}
	if (k == 3)
		ft_valid_room3(ers, *l, 0);
	return (0);
}

int		ft_t_link(t_lem *ers, char *line)
{
	t_str	*l1;
	int		i;

	l1 = ers->link;
	if (l1->str == NULL || line != NULL)
	{
		if (l1->str == NULL && ft_t_link_b(line, 1, l1))
			return (1);
		while ((i = -1) == -1)
		{
			while (++i >= 0 && l1->str[i] == line[i])
			{
				if (l1->str[i + 1] == '\0' && line[i + 1] == '\0')
					return (1);
			}
			if (ft_loop(line, l1->str, 0, ers) == 0)
				return (1);
			if (l1->next == NULL)
				break ;
			l1 = l1->next;
		}
		ft_t_link_b(line, 2, l1);
		return (1);
	}
	return (0);
}

int		ft_loop(char *line, char *link, int i, t_lem *ers)
{
	int		j;

	j = ers->i;
	while (line[j] == link[i] && ++i)
	{
		if (++j && ((line[j] == '\0' && link[i] != '-')
					|| (line[j] != '\0' && link[i] == '-')))
			return (1);
	}
	if (line[j] != '\0' || link[i] != '-')
		return (1);
	i = 0;
	while (link[i] && link[i] != '-')
		i++;
	j = 0;
	i++;
	while (line[j] == link[i] && ++i)
	{
		if (++j && ((line[j] == '-' && link[i] != '\0')
					|| (line[j] != '-' && link[i] == '\0')))
			return (1);
	}
	if (line[j] != '-' || link[i] != '\0')
		return (1);
	return (0);
}

void	ft_if_one(t_lem *ers)
{
	int		i;
	char	*s;

	i = 1;
	while (i <= ers->ant)
	{
		s = ft_itoa(i);
		ft_putchar('L');
		ft_putstr(s);
		ft_putchar('-');
		ft_putstr(ers->endz->room);
		ft_putchar(' ');
		ft_strdel(&s);
		i++;
	}
}

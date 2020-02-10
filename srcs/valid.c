/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:25:01 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/16 12:25:03 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_valid_ants(t_lem *ers, char *line)
{
	int		i;

	i = 0;
	if (ft_isdigit(line[0]) == 1)
	{
		ers->ant = ft_atoi(line);
		(ers->ant <= 0) ? ers->error = 1 : 0;
		while (ft_isdigit(line[i]) != 0)
			i++;
		(line[i] != '\0') ? ers->error = 1 : 0;
	}
	(ft_isdigit(line[0]) != 1) ? ers->error = 1 : 0;
	if (ers->error == 0)
		ers->valid = 1;
}

int		ft_valid_room(t_lem *ers, const char *line)
{
	int		i;

	i = 0;
	if (((ft_strncmp(line, "##start", ft_strlen(line)) == 0
													&& ers->start != NULL)
			|| (ft_strncmp(line, "##end", ft_strlen(line)) == 0
													&& ers->end != NULL)))
		return (0);
	if (line[0] && line[0] == '#' && line[1] != '#')
		return (2);
	if (line[0] && line[0] == '#' && line[1] == '#')
		return (1);
	if (ft_strchr(line, '-'))
		return (0);
	return (ft_valid_room2(line, i, ers, 0));
}

int		ft_valid_room2(const char *line, int i, t_lem *ers, int k)
{
	if (line[0] && line[0] != '#' && line[0] != 'L')
	{
		while (line[i] && line[i] != ' ')
			i++;
		(k == 0) ? ers->tmp = ft_strndup(line, i) : ers->tmp;
		(k == 0) ? ers->i = i + 1 : ers->i;
		if ((!line[i] || line[i] != ' '))
			return (0);
		if (++i && ft_atoi(&line[i]) >= 0)
		{
			while (line[i] && ft_isdigit(line[i]))
				i++;
			if (!line[i] || line[i] != ' ')
				return (0);
			if (++i && ft_atoi(&line[i]) >= 0)
			{
				while (line[i] && ft_isdigit(line[i]) != 0)
					i++;
				if (line[i] != '\0')
					return (0);
				return (3);
			}
		}
	}
	return (0);
}

int		ft_valid_room3(t_lem *ers, const char *line, int i)
{
	if (ers->b == 1 || ers->b == 2)
	{
		while (line[i] && line[i] != ' ')
			i++;
		(ers->b == 1) ? ers->start = ft_strndup(line, i) : NULL;
		(ers->b == 2) ? ers->end = ft_strndup(line, i) : NULL;
		ers->b = 0;
		ers->t = 1;
	}
	if (ers->b == 0)
	{
		if (ft_t_room(ers) == 0)
			ers->error = 1;
		free(ers->tmp);
		ers->tmp = NULL;
		ers->tmp1 = ft_strdup(&line[ers->i]);
		if (ft_t_coord(ers) == 0)
			ers->error = 1;
		free(ers->tmp1);
		ers->tmp1 = NULL;
	}
	return (0);
}

int		ft_valid_link(t_lem *ers, char *s, int i, const char *line)
{
	t_str	*r1;

	ers->l = ft_strlen(s);
	ers->p = ft_strlen(&line[i]);
	r1 = ers->input->next;
	while (1)
	{
		if (r1->str[0] != '#')
		{
			if (i == 1 && ft_strncmp(r1->str, s, ers->l) == 0)
				return (1);
			if (i != 1 && (ft_strncmp(r1->str, &line[i], ers->p) != 0
				&& ft_strcmp(s, &line[i]) == 0))
				return (0);
		}
		if (r1->next == NULL)
			break ;
		r1 = r1->next;
		if (r1 == ers->input1)
			break ;
	}
	if (i == 1)
		return (0);
	return (1);
}

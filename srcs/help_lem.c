/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:32:34 by bkuksa            #+#    #+#             */
/*   Updated: 2019/05/15 18:32:36 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_if_valid_next(t_lem *ers, char *line)
{
	if (line[0] && line[0] == '#' && line[1] != '#')
		return (0);
	if (ft_strchr(line, '-') != NULL)
	{
		if (ers->valid == 1 && (ers->start == NULL || ers->end == NULL)
														&& (ers->error = 1))
			return (0);
		else if ((ers->valid = 2))
		{
			ers->input1 = ers->input2;
			return (0);
		}
	}
	return (1);
}

char	*ft_strndup(const char *s, int n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		ft_t_link_b(char *line, int j, t_str *l1)
{
	if (j == 1)
	{
		l1->str = ft_strdup(line);
		l1->next = NULL;
	}
	if (j == 2)
	{
		l1->next = (t_str *)ft_memalloc(sizeof(t_str));
		l1 = l1->next;
		l1->str = ft_strdup(line);
		l1->next = NULL;
	}
	return (1);
}

void	ft_write(t_lem *ers)
{
	t_str	*l1;

	l1 = ers->input;
	while (1)
	{
		ft_putstr(l1->str);
		ft_putchar('\n');
		if (l1->next == NULL)
			break ;
		l1 = l1->next;
	}
}

char	*ft_cut(char *s1, const char *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] && s2[i] && s1[i] == s2[i] && s1[i] != '-')
		i++;
	if (s1[i] == '-' && !s2[i])
	{
		i = 0;
		while (s1[i] && s1[i] != '-')
			i++;
		i++;
		s = ft_strdup(&s1[i]);
		return (s);
	}
	i = 0;
	while (s1[i] && s1[i] != '-')
		i++;
	if (s1[i] != '-')
		return (NULL);
	s = ft_strndup(s1, i);
	return (s);
}

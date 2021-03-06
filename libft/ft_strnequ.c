/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:26:34 by bkuksa            #+#    #+#             */
/*   Updated: 2018/11/02 13:27:20 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && (int)n >= 0)
	{
		s2++;
		s1++;
		n--;
		if (*s1 != *s2 && (int)n != 0)
			return (0);
	}
	if (*s1 != *s2 && (int)n != 0)
		return (0);
	return (1);
}

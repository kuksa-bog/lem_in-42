/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:34:29 by bkuksa            #+#    #+#             */
/*   Updated: 2019/07/31 17:34:35 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;

}					t_coord;

typedef struct		s_str
{
	char			*str;
	struct s_str	*next;

}					t_str;

typedef struct		s_atm
{
	struct s_room	*fin;
	int				ant;
	int				count;
	struct s_atm	*next;
}					t_atm;

typedef struct		s_room
{
	int				stop;
	int				len;
	char			*room;
	struct s_room	*turn;
	struct s_room	*prev;
	struct s_room	*next;
	struct s_atm	*atm;
}					t_room;

typedef struct		s_route
{
	int				count;
	int				ant;
	int				ants;
	int				len;
	struct s_atm	*atm;
	struct s_route	*next;
}					t_route;

typedef struct		s_lem
{
	char			*str;
	t_room			*turn;
	t_room			*turn2;
	t_room			*turn3;
	t_route			*route;
	t_room			*endz;
	t_room			*startz;
	t_room			*now;
	t_room			*now1;
	t_room			*now2;
	int				k;
	int				k2;
	int				count;
	int				ant3;
	int				v;
	int				f;
	int				c;
	int				h;
	int				x;
	int				y;
	size_t			l;
	size_t			p;
	int				t;
	int				fd;
	t_room			*room;
	t_coord			*coord;
	t_str			*link;
	t_str			*input;
	t_str			*input1;
	t_str			*input2;
	char			*start;
	char			*end;
	char			*tmp;
	char			*tmp1;
	int				ant;
	int				error;
	int				b;
	int				i;
	int				line;
	int				valid;
}					t_lem;

t_lem				*ft_initialization(void);
void				ft_get_graf(t_lem *ers);
int					ft_get_room(t_lem *ers, char **line);
int					ft_get_link(t_lem *ers, char *l);
int					ft_get_link2(t_lem *ers, char *l, int i);

int					ft_valid_room(t_lem *ers, const char *line);
int					ft_valid_room2(const char *line, int i, t_lem *ers,
					int k);
void				ft_valid_ants(t_lem *ers, char *line);
int					ft_valid_room3(t_lem *ers, const char *line, int i);
int					ft_valid_link(t_lem *ers, char *s, int i,
					const char *line);

int					ft_t_room(t_lem *ers);
int					ft_t_coord(t_lem *ers);
int					ft_t_coord_b(int i, t_lem *ers, int j, t_coord *c1);
int					ft_t_link(t_lem *ers, char *line);
int					ft_loop(char *line, char *link, int i, t_lem *ers);
int					ft_t_room_b(t_lem *ers, int j, t_room *r1);

int					ft_if_valid_next(t_lem *ers, char *line);
int					ft_t_link_b(char *line, int j, t_str *l1);
char				*ft_strndup(const char *s, int n);
void				ft_write(t_lem *ers);

void				ft_get_alg(t_lem *ers);
void				ft_initial_room(t_lem *ers, t_str *link, t_str *link2);
char				*ft_cut_1(t_str *link, int i);
t_room				*ft_search_room(t_lem *ers, char *s);
void				ft_new_atm(t_room *r1, t_room *r2, t_atm *atm);

void				ft_alg_room(t_lem *ers, t_room *r, t_atm *atm, t_room *r2);
void				ft_route(t_lem *ers, t_room *end, t_room *prev);
int					ft_route2(t_lem *ers, t_room *end, t_room *prev,
					t_route *r);
void				ft_route3(t_lem *ers, t_room *end, t_room *prev);
int					ft_if_new_route(t_lem *ers, t_room *end, t_room *prev);
void				ft_alg_new_room(t_lem *ers, t_room *r, t_room *p);
int					ft_search_in_turn(t_lem *ers, t_room *r, int i);
void				ft_clean_graf(t_lem *ers);

void				ft_run_ant(t_lem *ers);
void				ft_run_ant2(t_lem *ers);
void				ft_if_run(t_lem *ers);
void				ft_run(t_lem *ers, t_route *r, t_atm *a, t_atm *a2);
void				ft_run2(t_lem *ers, t_route *r, t_atm *atm2);
void				ft_if_one(t_lem *ers);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:04:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/10 14:06:30 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_cam(t_data *sl)
{
	if (sl->map.w * 128 > sl->win.w)
	{
		if (sl->pl.pos.x >= sl->win.w / 2)
			sl->map.pos.x = -128 * (((sl->pl.pos.x - (sl->win.w / 2)) / 128));
		if (sl->map.pos.x * -1 > (sl->map.w * 128) - sl->win.w)
			sl->map.pos.x = (sl->map.w * -128) + sl->win.w;
	}
	if (sl->map.h * 128 > sl->win.h)
	{
		if (sl->pl.pos.y >= sl->win.h / 2)
			sl->map.pos.y = -128 * (((sl->pl.pos.y - (sl->win.h / 2)) / 128));
		if (sl->map.pos.y * -1 > (sl->map.h * 128) - sl->win.h)
			sl->map.pos.y = (sl->map.h * -128) + sl->win.h;
	}
}

static void	init_pl(t_entity *e, int x, int y)
{
	e->id = 0;
	e->pos.x = x * 128;
	e->pos.y = y * 128;
	e->tpos.x = 40;
	e->tpos.y = 32;
	e->w = 48;
	e->h = 92;
	e->dir = 0;
	e->nb_mv = 0;
	e->d = 0;
	e->inmove = 0;
	e->animation = 0;
}

static void	init_dog(t_data *sl, int x, int y)
{
	int	i;

	i = 0;
	while (i < sl->nb_dogs)
	{
		sl->dog[i].id = i + 1;
		sl->dog[i].pos.x = x * 128;
		sl->dog[i].pos.y = y * 128;
		sl->dog[i].tpos.x = 32;
		sl->dog[i].tpos.y = 32;
		sl->dog[i].w = 64;
		sl->dog[i].h = 92;
		sl->dog[i].dir = 0;
		sl->dog[i].nb_mv = 0;
		sl->dog[i].d = 0;
		sl->dog[i].inmove = 0;
		sl->dog[i].animation = 0;
		i++;
	}
}

void	init_pos(t_data *sl)
{
	int	x;
	int	y;

	x = -1;
	while (++x < sl->map.w)
	{
		y = -1;
		while (++y < sl->map.h)
		{
			if (get_tile(sl, x, y) == 'P')
			{
				init_pl(&(sl->pl), x, y);
				init_cam(sl);
			}
			if (get_tile(sl, x, y) == 'E')
			{
				sl->map.end.x = x * 128;
				sl->map.end.y = y * 128;
				init_dog(sl, x, y);
			}
		}
	}
}

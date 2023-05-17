/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:33 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/16 17:59:01 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	transparence(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = (((c1 >> 16) & 0xFF) * (1.0 - t) + ((c2 >> 16) & 0xFF) * t);
	if (r > 255)
		r = 255;
	g = (((c1 >> 8) & 0xFF) * (1.0 - t) + ((c2 >> 8) & 0xFF) * t);
	if (g > 255)
		g = 255;
	b = (c1 & 0xFF) * (1.0 - t) + ((c2 & 0xFF) * t);
	if (b > 255)
		b = 255;
	return (255 << 24 | r << 16 | g << 8 | b);
}

void	update_night(t_data *sl)
{
	int	i;

	if (sl->pl.nb_mv < sl->nb_case)
		sl->trans = (((float)sl->pl.nb_mv
					/ (float)(sl->map.w * sl-> map.h)) * 4) / 5;
	if (sl->pl.nb_mv >= sl->nb_case && sl->dog[0].alive)
	{
		sl->need_pet = 250;
		sl->wolf.alive = 1;
		sl->wolf.inmove = 1;
		i = -1;
		while (++i < sl->nb_dogs)
			sl->dog[i].alive = 0;
		ft_putstr_fd("The big bad wolf is...\nCOMMING!!!!!\n", 1);
	}
}


static int	move_wolf(t_data *sl, t_entity *e, int x, int y)
{
	if (!test_collision(sl, e, x, y))
	{
		e->pos.x += x;
		e->pos.y += y;
	}
	return (0);
}

static void	wolf_action(t_data *sl, t_entity *e)
{
	if (e->inmove && sl->pl.alive)
	{
		if (e->dir == 0)
			move_wolf(sl, e, 0, 14);
		if (e->dir == 1)
			move_wolf(sl, e, 0, -14);
		if (e->dir == 2)
			move_wolf(sl, e, 14, 0);
		if (e->dir == 3)
			move_wolf(sl, e, -14, 0);
	}
	if (entity_collision(&(sl->pl), e) && sl->pl.alive)
	{
		sl->pl.alive = 0;
		e->inmove = 0;
		e->dir = 4;
		e->animation = 1;
		sl->pl.dir = 4;
		sl->pl.pos.x = e->pos.x;
		sl->pl.pos.y = e->pos.y;
		sl->pl.animation = 1;
		sl->time = 0;
		ft_putstr_fd("NIOM NIOM NIOM!!!\n You lost...\n", 1);
	}
}

void	wolf_manager(t_data *sl, t_entity *e)
{
	static int	time;

	if (time > 100)
		time = 0;
	if (!(time % 2) && sl->pl.alive)
	{
		if (e->pos.y < sl->pl.pos.y)
			e->dir = 0;
		else
			e->dir = 1;
		wolf_action(sl, e);
		if (e->pos.x < sl->pl.pos.x)
			e->dir = 2;
		else
			e->dir = 3;
		wolf_action(sl, e);
	}
	time++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/14 17:21:32 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wall_collision(t_data *sl, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = sl->cat.pos.x + x + 64;
	next_y = sl->cat.pos.y + y + 64;
	if (get_tile(sl, next_x / 128, next_y / 128) == '1')
		collision = 1;
	if (get_tile(sl, next_x / 128, (next_y + 92) / 128) == '1')
		collision = 1;
	if (get_tile(sl, (next_x + 64) / 128, next_y / 128) == '1')
		collision = 1;
	if (get_tile(sl, (next_x + 64) / 128, (next_y + 92) / 128) == '1')
		collision = 1;
	return (collision);
}

int	move_cat(t_data *sl, int x, int y)
{
	if (!wall_collision(sl, x, y))
	{
		sl->cat.pos.x += x;
		sl->cat.pos.y += y;
	}
	else
	{
		sl->cat.dir++;
		if (sl->cat.dir > 3)
			sl->cat.dir = 0;
	}
	return (0);
}

void	cat_action(t_data *sl, int time)
{
	if (sl->cat.inmove && !(time % 3))
	{
		if (sl->cat.dir == 0)
			move_cat(sl, 0, 16);
		if (sl->cat.dir == 1)
			move_cat(sl, 0, -16);
		if (sl->cat.dir == 2)
			move_cat(sl, 16, 0);
		if (sl->cat.dir == 3)
			move_cat(sl, -16, 0);
		if (entity_collision(&(sl->pl), &(sl->cat)) && sl->need_pet == 201)
		{
			printf ("need...to...peeeeeet\n");
			sl->need_pet = 0;
			sl->cat.inmove = 0;
			sl->cat.pos.x = sl->pl.pos.x;
			sl->cat.pos.y = sl->pl.pos.y;
			sl->pl.nb_mv += 100;
			time = 0;
		}
	}
}

void	cat_manager(t_data *sl, int r)
{
	static int	time;

	if (sl->need_pet > 200)
	{
		if (time > 76)
		{
			time = 0;
			sl->need_pet = 201;
			r = (sl->pl.pos.x + sl->pl.pos.y + sl->pl.d + r);
			if (r % 3 == 0)
				sl->cat.inmove = 0;
			else
				sl->cat.inmove = 1;
			sl->cat.dir = (r % 4);
		}
		cat_action(sl, time);
	}
	else
		sl->need_pet++;
	time++;
}

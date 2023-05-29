/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/17 15:21:41 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	entity_collision(t_entity *e1, t_entity *e2)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = e1->pos.x + e1->tpos.x;
	y1 = e1->pos.y + e1->tpos.y;
	x2 = e2->pos.x + e1->tpos.x;
	y2 = e2->pos.y + e1->tpos.y;
	if ((x1 >= x2 && x1 < x2 + e2->h && y1 >= y2 && y1 < y2 + e2->h)
		|| (x1 >= x2 && x1 < x2 + e2->h && y1 >= y2 && y1 < y2 + e2->h)
		|| (x1 + e1->w >= x2 && x1 + e1->w < x2 + e2->w && y1 >= y2 && y1
			< y2 + e2->h) || (x1 + e1->w >= x2 && x1 + e1->w < x2 + e2->w && y1
			+ e1->h >= y2 && y1 + e1->h < y2 + e2->h))
		return (1);
	if ((x2 >= x1 && x2 < x1 + e1->h && y2 >= y1 && y2 < y1 + e1->h)
		|| (x2 >= x1 && x2 < x1 + e1->h && y2 >= y1 && y2 < y1 + e1->h)
		|| (x2 + e2->w >= x1 && x2 + e2->w < x1 + e1->w && y2 >= y1 && y2
			< y1 + e1->h) || (x2 + e2->w >= x1 && x2 + e2->w < x1 + e1->w && y2
			+ e2->h >= y1 && y2 + e2->h < y1 + e1->h))
		return (1);
	return (0);
}

static int	collision_action(t_data *sl, t_entity *e, int x, int y)
{
	if (!e->id)
	{
		if (get_tile(sl, x, y) == 'C')
		{
			set_tile(sl, x, y, 'c');
			reload_tile_img(sl, x * 128, y * 128);
			if (get_tile(sl, sl->map.end.x / 128, sl->map.end.y / 128) == 'E')
				set_tile(sl, sl->map.end.x / 128, sl->map.end.y / 128, 'I');
			if (!is_still(sl->map.map, 'C'))
				set_tile(sl, sl->map.end.x / 128, sl->map.end.y / 128, 'S');
			reload_tile_img(sl, sl->map.end.x, sl->map.end.y);
		}
		if (get_tile(sl, x, y) == 'S')
		{
			ft_putstr_fd("You Won !!\n", 1);
			close_window(sl);
		}
	}
	if (get_tile(sl, x, y) == '1')
		return (1);
	return (0);
}

int	test_collision(t_data *sl, t_entity *e, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = e->pos.x + x + e->tpos.x;
	next_y = e->pos.y + y + e->tpos.y;
	if (get_tile(sl, next_x / 128, next_y / 128) != '0')
		collision += collision_action(sl, e, next_x / 128, next_y / 128);
	if (get_tile(sl, next_x / 128, (next_y + e->h) / 128) != '0')
		collision += collision_action(sl, e, next_x / 128, (next_y + e->h)
				/ 128);
	if (get_tile(sl, (next_x + e->w) / 128, next_y / 128) != '0')
		collision += collision_action(sl, e, (next_x + e->w) / 128, next_y
				/ 128);
	if (get_tile(sl, (next_x + e->w) / 128, (next_y + e->h) / 128) != '0')
		collision += collision_action(sl, e, (next_x + e->w) / 128,
				(next_y + e->h) / 128);
	return (collision);
}

int	move_player(t_data *sl, int x, int y, int dir)
{
	sl->pl.dir = dir;
	sl->pl.inmove = 1;
	if (!test_collision(sl, &(sl->pl), x, y))
	{
		sl->pl.d += 10;
		if (sl->pl.d >= 128)
		{
			ft_putmove_fd(sl->pl.nb_mv++, 1);
			sl->pl.d = 0;
		}
		sl->pl.pos.x += x;
		sl->pl.pos.y += y;
		if (x != 0 && sl->pl.pos.x >= sl->win.w / 2 && ((sl->map.w * 128)
				- sl->pl.pos.x) > sl->win.w / 2)
			if (sl->map.pos.x - x <= 0 && sl->map.pos.x - x - sl->win.w
				>= sl->map.w * -128)
				sl->map.pos.x = -sl->pl.pos.x + sl->win.w / 2;
		if (y != 0 && sl->pl.pos.y >= sl->win.h / 2 && ((sl->map.h * 128)
				- sl->pl.pos.y) > sl->win.h / 2)
			if (sl->map.pos.y - y <= 0 && sl->map.pos.y - y - sl->win.h
				>= sl->map.h * -128)
				sl->map.pos.y = -sl->pl.pos.y + sl->win.h / 2;
	}
	return (0);
}

void	event_manager(t_data *sl)
{
	if (sl->need_pet > 110)
	{
		if (sl->keys.up)
			move_player(sl, 0, -11, 1);
		if (sl->keys.down)
			move_player(sl, 0, 11, 0);
		if (sl->keys.left)
			move_player(sl, -11, 0, 3);
		if (sl->keys.right)
			move_player(sl, 11, 0, 2);
	}
}

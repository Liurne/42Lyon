/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/04 11:58:01 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collision_action(t_data *sl, int x, int y)
{
	if (get_tile(sl, x, y) == 'C')
	{
		put_tile(sl, x, y, '0');
		reload_tile_img(sl, x * 64, y * 64);
		if (get_tile(sl, sl->map.end.x / 64, sl->map.end.y / 64) == 'E')
			put_tile(sl, sl->map.end.x / 64, sl->map.end.y / 64, 'I');
		if (!is_still(sl, 'C'))
			put_tile(sl, sl->map.end.x / 64, sl->map.end.y / 64, 'S');
		reload_tile_img(sl, sl->map.end.x, sl->map.end.y);
	}
	if (get_tile(sl, x, y) == 'S')
	{
		printf("You Won !!\n");
		close_window(sl);
	}
	if (get_tile(sl, x, y) == '1')
		return (1);
	return (0);
}

int	test_collision(t_data *sl, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = sl->pl.pos.x + x + 16;
	next_y = sl->pl.pos.y + y + 16;
	if (get_tile(sl, next_x / 64, next_y / 64) != '0')
		collision += collision_action(sl, next_x / 64, next_y / 64);
	if (get_tile(sl, next_x / 64, (next_y + 46) / 64) != '0')
		collision += collision_action(sl, next_x / 64, (next_y + 46) / 64);
	if (get_tile(sl, (next_x + 32) / 64, next_y / 64) != '0')
		collision += collision_action(sl, (next_x + 32) / 64, next_y / 64);
	if (get_tile(sl, (next_x + 32) / 64, (next_y + 46) / 64) != '0')
		collision += collision_action(sl, (next_x + 32) / 64,
				(next_y + 46) / 64);
	return (collision);
}

int	move_player(t_data *sl, int x, int y, int dir)
{
	sl->pl.dir = dir;
	sl->pl.inmove = 1;
	if (!test_collision(sl, x, y))
	{
		sl->pl.d += 8;
		if (sl->pl.d == 64)
		{
			sl->pl.nb_mv++;
			printf("nb move :%ld\n", sl->pl.nb_mv);
			sl->pl.d = 0;
		}
		sl->pl.pos.x += x;
		sl->pl.pos.y += y;
		if ((sl->pl.pos.x >= sl->win.w / 2 && x > 0 && (sl->map.w * 64)
				+ sl->map.pos.x > sl->win.w) || (sl->pl.pos.x >= sl->win.w
				/ 2 - 64 && x < 0 && sl->map.pos.x < 0))
			sl->map.pos.x -= x;
		if ((sl->pl.pos.y >= sl->win.h / 2 && y > 0 && (sl->map.h * 64)
				+ sl->map.pos.y > sl->win.h) || (sl->pl.pos.y >= sl->win.h
				/ 2 - 64 && y < 0 && sl->map.pos.y < 0))
			sl->map.pos.y -= y;
	}
	return (0);
}

int	event_manager(int keycode, t_data *sl)
{
	if (keycode == 65307)
		close_window(sl);
	if (keycode == 119 || keycode == 122)
		move_player(sl, 0, -8, 1);
	if (keycode == 115)
		move_player(sl, 0, 8, 0);
	if (keycode == 97 || keycode == 113)
		move_player(sl, -8, 0, 3);
	if (keycode == 100)
		move_player(sl, 8, 0, 2);
	return (keycode);
}

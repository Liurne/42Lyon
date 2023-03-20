/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/20 17:42:11 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_player(t_data *sl, int x, int y, int dir)
{
	sl->pl.dir = dir;
	if (get_tile(sl, (sl->pl.pos.x + x) / 64, (sl->pl.pos.y + y) / 64) != '1')
	{
		sl->pl.nb_mv++;
		sl->pl.pos.x += x;
		sl->pl.pos.y += y;
		if ((sl->pl.pos.x >= sl->win.w / 2 && x > 0 && (sl->map.width * 64)
				+ sl->map.pos.x > sl->win.w) || (sl->pl.pos.x >= sl->win.w
				/ 2 - 64 && x < 0 && sl->map.pos.x < 0))
			sl->map.pos.x -= x;
		if ((sl->pl.pos.y >= sl->win.h / 2 && y > 0 && (sl->map.height * 64)
				+ sl->map.pos.y > sl->win.h) || (sl->pl.pos.y >= sl->win.h
				/ 2 - 64 && y < 0 && sl->map.pos.y < 0))
			sl->map.pos.y -= y;
	}
	return (0);
}

int	event_manager(int keycode, t_data *sl)
{
	printf("keycode:%d\n", keycode);
	if (keycode == 65307)
		close_window(sl);
	if (keycode == 119)
	{
		printf("up\n");
		move_player(sl, 0, -64, 1);
	}
	if (keycode == 115)
	{
		printf("down\n");
		move_player(sl, 0, 64, 0);
	}	
	if (keycode == 97)
	{
		printf("left\n");
		move_player(sl, -64, 0, 3);
	}
	if (keycode == 100)
	{
		printf("right\n");
		move_player(sl, 64, 0, 2);
	}
	return (keycode);
}

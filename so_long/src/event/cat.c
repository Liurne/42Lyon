/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/12 18:30:17 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	test_collision_e(t_data *sl, int x, int y)
{
	int	next_x;
	int	next_y;
	int	collision;

	collision = 0;
	next_x = sl->cat.pos.x + x + 16;
	next_y = sl->cat.pos.y + y + 16;
	if (get_tile(sl, next_x / 64, next_y / 64) == '1')
		collision = 1;
	if (get_tile(sl, next_x / 64, (next_y + 46) / 64) == '1')
		collision = 1;
	if (get_tile(sl, (next_x + 32) / 64, next_y / 64) == '1')
		collision = 1;
	if (get_tile(sl, (next_x + 32) / 64, (next_y + 46) / 64) == '1')
		collision = 1;
	return (collision);
}

int	move_cat(t_data *sl, int x, int y)
{
	if (!test_collision_e(sl, x, y))
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

void	cat_manager(t_data *sl, int r)
{
	static int	time;

	if (time > 151)
	{
		time = 0;
		r = (sl->pl.pos.x + sl->pl.pos.y + sl->pl.d + r);
		if (r % 3 == 2)
			sl->cat.inmove = 0;
		else
			sl->cat.inmove = 1;
		sl->cat.dir = (r % 4);
	}
	if (sl->cat.inmove && !(time % 7))
	{
		if (sl->cat.dir == 0)
			move_cat(sl, 0, 8);
		if (sl->cat.dir == 1)
			move_cat(sl, 0, -8);
		if (sl->cat.dir == 2)
			move_cat(sl, 8, 0);
		if (sl->cat.dir == 3)
			move_cat(sl, -8, 0);
	}
	time++;
}

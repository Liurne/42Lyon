/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:35:45 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/25 14:42:50 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_entity(t_data *sl, t_entity *e)
{
	int	x;
	int	y;

	x = -1;
	while (x++ < e->tex[e->dir][e->animation].img_w -1)
	{
		y = -1;
		while (y++ < e->tex[e->dir][e->animation].img_h - 1)
		{
			if (get_pixel(&(e->tex[e->dir][e->animation]), x, y) >> 24 == 0
				&& e->pos.x + x + sl->map.pos.x > 0 && e->pos.x + x
				+ sl->map.pos.x < sl->win.w && e->pos.y + y + sl->map.pos.y
				> 0 && e->pos.y + y + sl->map.pos.y < sl->win.h)
				put_pixel(&(sl->win.renderer), e->pos.x + x + sl->map.pos.x,
					e->pos.y + y + sl->map.pos.y,
					get_pixel(&(e->tex[e->dir][e->animation]), x, y));
		}
	}
}

void	display_hitbox(t_data *sl, t_entity *e)
{
	int	x;
	int	y;

	x = e->tpos.x - 1;
	while (x++ < e->w)
	{
		y = e->tpos.y - 1;
		while (y++ < e->h)
		{
			if (e->pos.x + x + sl->map.pos.x > 0 && e->pos.x + x
				+ sl->map.pos.x < sl->win.w && e->pos.y + y + sl->map.pos.y
				> 0 && e->pos.y + y + sl->map.pos.y < sl->win.h)
				put_pixel(&(sl->win.renderer), e->pos.x + x + sl->map.pos.x,
					e->pos.y + y + sl->map.pos.y, 0xFFFF0000);
		}
	}
}
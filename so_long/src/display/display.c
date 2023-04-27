/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:13:30 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 17:50:04 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dst);
}

static int	animation(t_data *sl)
{
	static int	frame;

	if (frame >= 8)
	{
		sl->anim++;
		if (sl->anim > 3)
			sl->anim = 0;
		if (sl->pl.inmove)
			sl->pl.animation = sl->anim;
		else
			sl->pl.animation = 0;
		if (sl->dog.inmove)
			sl->dog.animation = sl->anim;
		else
			sl->dog.animation = 0;
		frame = 0;
		sl->pl.inmove = 0;
	}
	++frame;
	return (frame);
}

int	render_display(t_data *sl)
{
	int	x;
	int	y;

	x = -1;
	while (x++ < sl->win.w && x - sl->map.pos.x < sl->map.w * 128)
	{
		y = -1;
		while (y++ < sl->win.h && y - sl->map.pos.y < sl->map.h * 128)
			put_pixel(&(sl->win.renderer), x, y, get_pixel(&(sl->map.img),
					x - sl->map.pos.x, y - sl->map.pos.y));
	}
	display_entity(sl, &(sl->dog));
	display_entity(sl, &(sl->pl));
	return (0);
}

int	update_display(t_data *sl)
{
	dog_manager(sl, animation(sl));
	render_display(sl);
	mlx_put_image_to_window(sl->win.mlx, sl->win.win,
		sl->win.renderer.img, 0, 0);
	return (0);
}
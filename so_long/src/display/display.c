/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:45:30 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/16 18:10:44 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_display(t_data *sl)
{
	mlx_put_image_to_window(sl->win.mlx, sl->win.win, sl->pl.img->img,
		sl->pl.pos.x, sl->pl.pos.y);
	mlx_put_image_to_window(sl->win.mlx, sl->win.win, sl->map.img.img, 0, 0);
	return (0);
}

int	render_display(t_data *sl)
{
	int	x;
	int	y;

	x = 0;
	while (x < 500 && x -sl->map.pos.x < sl->map.width)
	{
		y = 0;
		while (y < 500 && y - sl->map.pos.y < sl->map.height)
		{
			put_pixel(sl->win.renderer, x, y, get_pixel(sl->map.img, x +(-1 * sl->map.pos.x)));
			y++;
		}
		x++;
	}
}

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
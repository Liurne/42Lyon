/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:13:30 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/04 15:13:52 by jcoquard         ###   ########.fr       */
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

static void	animation(t_data *sl)
{
	int	i;

	i = -1;
	if (sl->time >= 8)
	{
		sl->anim++;
		if (sl->anim > 3)
			sl->anim = 0;
		animation_entity(sl, &(sl->pl));
		while (++i < sl->nb_dogs)
			animation_entity(sl, &(sl->dog[i]));
		sl->time = 0;
		sl->pl.inmove = 0;
	}
	++sl->time;
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
	x = -1;
	while (++x < sl->nb_dogs)
		display_dog(sl, &(sl->dog[x]));
	display_entity(sl, &(sl->pl));
	return (0);
}

int	update_display(t_data *sl)
{
	char	*tmp;
	int		i;

	event_manager(sl);
	animation(sl);
	i = -1;
	while (++i < sl->nb_dogs)
		dog_manager(sl, &(sl->dog[i]));
	render_display(sl);
	mlx_put_image_to_window(sl->win.mlx, sl->win.win,
		sl->win.renderer.img, 0, 0);
	mlx_string_put(sl->win.mlx, sl->win.win, 10, 20, 0xFF000000,
		"Number of tiles traveled : ");
	(void) tmp;
	tmp = ft_itoa(sl->pl.nb_mv);
	mlx_string_put(sl->win.mlx, sl->win.win, 175, 21, 0xFF000000, tmp);
	free(tmp);
	mlx_string_put(sl->win.mlx, sl->win.win, 10, 35, 0xFF000000,
		"Number of boxes remaining : ");
	tmp = ft_itoa(is_still(sl->map.map, 'C'));
	mlx_string_put(sl->win.mlx, sl->win.win, 175, 36, 0xFF000000, tmp);
	free(tmp);
	if (sl->need_pet > 150 && sl->pl.dir == 4)
		sl->pl.dir = 0;
	return (0);
}

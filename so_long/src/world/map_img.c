/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:20:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/03 17:36:18 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_pixelmap(t_map *m, int x, int y, int img)
{
	put_pixel(&(m->img), x, y, get_pixel(&(m->tex[img]), x % 128, y % 128));
}

static void	wich_wall(t_map *map, int x, int y)
{
	if (x < 128 && y > 127 && y < (map->h - 1) * 128 + 1)
		put_pixelmap(map, x, y, 4);
	else if (x > (map->w - 1) * 128 + 1 && y > 127 && y < (map->h - 1) * 128
		+ 1)
		put_pixelmap(map, x, y, 5);
	else if (y < 127 && x > 127 && x < (map->w - 1) * 128 + 1)
		put_pixelmap(map, x, y, 3);
	else if (y > (map->h - 1) * 128 && x > 127 && x < (map->w - 1) * 128 + 1)
		put_pixelmap(map, x, y, 2);
	else if (y > (map->h - 1) * 128 && x < 128)
		put_pixelmap(map, x, y, 9);
	else if (y > (map->h - 1) * 128 && x > (map->w - 1) * 128)
		put_pixelmap(map, x, y, 7);
	else if (y < 128 && x < 128)
		put_pixelmap(map, x, y, 8);
	else if (y < 128 && x > (map->w - 1) * 128)
		put_pixelmap(map, x, y, 6);
	else if (!((x / 128) % 2) && !((y / 128) % 2))
		put_pixelmap(map, x, y, 15);
	else
		put_pixelmap(map, x, y, 1);
}

static void	wich_tile(t_data *sl, int x, int y)
{
	if (get_tile(sl, x / 128, y / 128) == '0' || get_tile(sl,
			x / 128, y / 128) == 'P')
	{
		if (!((x / 128) % 3) && !((y / 128) % 3))
			put_pixelmap(&(sl->map), x, y, 14);
		else
			put_pixelmap(&(sl->map), x, y, 0);
	}
	else if (get_tile(sl, x / 128, y / 128) == '1')
		wich_wall(&(sl->map), x, y);
	else if (get_tile(sl, x / 128, y / 128) == 'E')
		put_pixelmap(&(sl->map), x, y, 11);
	else if (get_tile(sl, x / 128, y / 128) == 'C')
		put_pixelmap(&(sl->map), x, y, 10);
	else if (get_tile(sl, x / 128, y / 128) == 'I')
		put_pixelmap(&(sl->map), x, y, 12);
	else if (get_tile(sl, x / 128, y / 128) == 'S')
		put_pixelmap(&(sl->map), x, y, 13);
	else if (get_tile(sl, x / 128, y / 128) == 'c')
		put_pixelmap(&(sl->map), x, y, 16);
}

void	reload_tile_img(t_data *sl, int x, int y)
{
	int	tmp1;
	int	tmp2;

	tmp1 = x;
	tmp2 = y;
	while (x < tmp1 + 128)
	{
		y = tmp2;
		while (y < tmp2 + 128)
		{
			wich_tile (sl, x, y);
			y++;
		}
		x++;
	}
}

int	map_to_img(t_data *sl)
{
	int	x;
	int	y;

	new_img(sl, &(sl->map.img), sl->map.w * 128, sl->map.h * 128);
	x = 0;
	while (x < sl->map.w * 128)
	{
		y = 0;
		while (y < sl->map.h * 128)
		{
			wich_tile (sl, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/29 17:18:31 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	wich_wall(t_map *map, int x, int y)
{
	if (x < 64 && y > 63 && y < (map->h - 1) * 64 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[4]), x % 64, y % 64));
	else if (x > (map->w - 1) * 64 + 1 && y > 63 && y < (map->h - 1) * 64 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[5]), x % 64, y % 64));
	else if (y < 63 && x > 63 && x < (map->w - 1) * 64 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[3]), x % 64, y % 64));
	else if (y > (map->h - 1) * 64 && x > 63 && x < (map->w - 1) * 64 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[2]), x % 64, y % 64));
	else if (y > (map->h - 1) * 64 && x < 64)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[9]), x % 64, y % 64));
	else if (y > (map->h - 1) * 64 && x > (map->w - 1) * 64)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[7]), x % 64, y % 64));
	else if (y < 64 && x < 64)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[8]), x % 64, y % 64));
	else if (y < 64 && x > (map->w - 1) * 64)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[6]), x % 64, y % 64));
	else
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[1]), x % 64, y % 64));
}

static void	wich_tile(t_data *sl, int x, int y)
{
	if (get_tile(sl, x / 64, y / 64) == '0' || get_tile(sl, x / 64, y / 64) == 'P')
	{
		if (!((x / 64) % 3) && !((y / 64) % 3))
			put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[14]),
					x % 64, y % 64));
		else
			put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[0]),
					x % 64, y % 64));
	}
	else if (get_tile(sl, x / 64, y / 64) == '1')
		wich_wall(&(sl->map), x, y);
	else if (get_tile(sl, x / 64, y / 64) == 'E')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[11]),
				x % 64, y % 64));
	else if (get_tile(sl, x / 64, y / 64) == 'C')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[10]),
				x % 64, y % 64));
	else if (get_tile(sl, x / 64, y / 64) == 'I')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[12]),
				x % 64, y % 64));
	else if (get_tile(sl, x / 64, y / 64) == 'S')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[13]),
				x % 64, y % 64));
}

void	reload_tile_img(t_data *sl, int x, int y)
{
	int	tmp1;
	int	tmp2;

	tmp1 = x;
	tmp2 = y;
	while (x < tmp1 + 64)
	{
		y = tmp2;
		while (y < tmp2 + 64)
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

	new_img(sl, &(sl->map.img), sl->map.w * 64, sl->map.h * 64);
	x = 0;
	while (x < sl->map.w * 64)
	{
		y = 0;
		while (y < sl->map.h * 64)
		{
			wich_tile (sl, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

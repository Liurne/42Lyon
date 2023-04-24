/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:56:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/14 16:57:39 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	wich_wall(t_map *map, int x, int y)
{
	if (x < 128 && y > 127 && y < (map->h - 1) * 128 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[4]), x % 128, y % 128));
	else if (x > (map->w - 1) * 128 + 1 && y > 127 && y < (map->h - 1) * 128 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[5]), x % 128, y % 128));
	else if (y < 127 && x > 127 && x < (map->w - 1) * 128 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[3]), x % 128, y % 128));
	else if (y > (map->h - 1) * 128 && x > 127 && x < (map->w - 1) * 128 + 1)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[2]), x % 128, y % 128));
	else if (y > (map->h - 1) * 128 && x < 128)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[9]), x % 128, y % 128));
	else if (y > (map->h - 1) * 128 && x > (map->w - 1) * 128)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[7]), x % 128, y % 128));
	else if (y < 128 && x < 128)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[8]), x % 128, y % 128));
	else if (y < 128 && x > (map->w - 1) * 128)
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[6]), x % 128, y % 128));
	else
		put_pixel(&(map->img), x, y, get_pixel(&(map->tex[1]), x % 128, y % 128));
}

static void	wich_tile(t_data *sl, int x, int y)
{
	if (get_tile(sl, x / 128, y / 128) == '0' || get_tile(sl,
			x / 128, y / 128) == 'P')
	{
		if (!((x / 128) % 3) && !((y / 128) % 3))
			put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[14]),
					x % 128, y % 128));
		else
			put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[0]),
					x % 128, y % 128));
	}
	else if (get_tile(sl, x / 128, y / 128) == '1')
		wich_wall(&(sl->map), x, y);
	else if (get_tile(sl, x / 128, y / 128) == 'E')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[11]),
				x % 128, y % 128));
	else if (get_tile(sl, x / 128, y / 128) == 'C')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[10]),
				x % 128, y % 128));
	else if (get_tile(sl, x / 128, y / 128) == 'I')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[12]),
				x % 128, y % 128));
	else if (get_tile(sl, x / 128, y / 128) == 'S')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->map.tex[13]),
				x % 128, y % 128));
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

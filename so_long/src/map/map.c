/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/20 14:56:18 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_tile(t_data *sl, int x, int y)
{
	if (x < sl->map.width && y < sl->map.height)
		return (sl->map.map[(y * (sl->map.width + 1)) + x]);
	return ('\0');
}

static void	wich_tile(t_data *sl, int x, int y)
{
	if (get_tile(sl, x / 64, y / 64) == '0')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->tex_map[0]),
				x % 64, y % 64));
	else if (get_tile(sl, x / 64, y / 64) == '1')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->tex_map[1]),
				x % 64, y % 64));
	else if (get_tile(sl, x / 64, y / 64) == 'E')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->tex_map[2]),
				x % 64, y % 64));
	else if (get_tile(sl, x / 64, y / 64) == 'C')
		put_pixel(&(sl->map.img), x, y, get_pixel(&(sl->tex_map[3]),
				x % 64, y % 64));
}

int	map_to_img(t_data *sl)
{
	int	x;
	int	y;

	new_img(sl, &(sl->map.img), sl->map.width * 64, sl->map.height * 64);
	x = 0;
	while (x < sl->map.width * 64)
	{
		y = 0;
		while (y < sl->map.height * 64)
		{
			wich_tile (sl, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

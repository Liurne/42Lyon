/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:59:36 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/28 18:48:39 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_map_size(t_data *sl)
{
	int	tmp;

	tmp = 0;
	while(sl->map.map[tmp] != '\n' && sl->map.map[tmp])
		tmp++;
	if (!sl->map.map[tmp])
		return (0);
	sl->map.w = tmp;
	if ((ft_strlen(sl->map.map) + 1) % (tmp + 1))
		return (0);
	sl->map.h = (ft_strlen(sl->map.map) + 1) / (tmp + 1);
	return (1);
}

void	find_pos(t_data *sl)
{
	int	x;
	int	y;

	x = 0;
	while (x < sl->map.w)
	{
		y = 0;
		while (y < sl->map.h)
		{
			if (get_tile(sl, x, y) == 'P')
			{
				printf("yep\n");
				sl->pl.pos.x = x * 64;
				sl->pl.pos.y = y * 64;
				printf("pos x:%d, y:%d\n",sl->pl.pos.x, sl->win.w / 2);
				if (sl->pl.pos.x >= sl->win.w / 2)
				{
					sl->map.pos.x = -64 * ((sl->pl.pos.x / 2) / 64);
					printf("ok\n");
				}
				if (sl->pl.pos.y >= sl->win.h / 2)
					sl->map.pos.y = -64 * ((sl->pl.pos.y / 2) / 64);
			}
			if (get_tile(sl, x, y) == 'E')
			{
				sl->map.end.x = x * 64;
				sl->map.end.y = y * 64;
			}
			y++;
		}
		x++;
	}
}

int	load_map(t_data *sl, char *path)
{
	(void)path;
	load_file(sl, path);
	if (!verif_map_size(sl))
		return (free(sl->map.map), 0);
	sl->map.pos.x = 0;
	sl->map.pos.y = 0;
	find_pos(sl);
	sl->pl.dir = 0;
	sl->pl.nb_mv = 0;
	return (1);
}